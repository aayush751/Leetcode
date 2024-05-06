/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:


    ListNode* reverseList(ListNode* head )
    {
        ListNode* curr = head, *prev = NULL, *next;

        if( curr -> next == NULL )
        {
            return head;
        }
        while( curr )
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        // ye quesiton next greater element hai...jo ki recursion se bhi bn skta hai and stack se bhi
        // hm isko stack and reursion se bnaegein 

        if( head == NULL )
        {
            return head;
        }

        ListNode* newList = reverseList( head );

        ListNode* prev = newList, *curr = newList -> next, *next;


        int maxSoFar = newList -> val;

        while( curr )
        {
            next = curr -> next;

            if( curr -> val < maxSoFar )
            {
                prev -> next = next;
                curr = next;
            }
            else
            {
                maxSoFar = curr -> val;
                prev = curr;
                curr = next;
            }
        }

        newList = reverseList(newList);
        return newList;
    }
};
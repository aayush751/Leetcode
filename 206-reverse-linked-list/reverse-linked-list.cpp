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
    ListNode* reverseList(ListNode* head) {


        // if( head == NULL or head -> next == NULL )
        // {
        //     return head;
        // }


        // ListNode* prev = NULL, *temp = head, *next = head -> next;

        // while( next )
        // {
        //     temp -> next = prev;
        //     prev = temp;
        //     temp = next;
        //     next = temp -> next;             
        // }

        // temp -> next = prev;

        // return temp;


        ListNode* prev = nullptr, *curr = head;

        while( curr )
        {
            ListNode* curNext = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = curNext;
        }

        return prev;
    }
};
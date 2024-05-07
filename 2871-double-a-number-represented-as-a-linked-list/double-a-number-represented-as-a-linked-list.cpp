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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr, *curr = head, *next;

        if( curr -> next == nullptr )
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
    ListNode* doubleIt(ListNode* head) {

        if( head == nullptr )
        {
            return head;
        }
        ListNode* newhead = reverseList( head );

        ListNode* i = newhead;
        ListNode* temp = nullptr;
        int carry = 0;
        while( i )
        {
            i -> val = i -> val + carry + i -> val;
            carry = i -> val / 10;
            i -> val = i -> val % 10;
            temp = i;
            i = i -> next;
        }


        if( carry != 0 )
        {
            ListNode* extra = new ListNode( carry );
            temp -> next = extra;
        }
        newhead = reverseList(newhead);
        return newhead;
    }
};
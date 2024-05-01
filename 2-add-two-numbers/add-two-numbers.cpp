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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if( l1 == NULL )
        {
            return l2;
        }

        if( l2 == NULL )
        {
            return l1;
        }

        ListNode* head = l1, *tail = l1;
        int carry = 0;

        while( l1 and l2 )
        {
            l1 -> val = l1 -> val + l2 -> val + carry;

            carry = l1 -> val / 10;

            l1 -> val = l1 -> val % 10;

            tail = l1;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }


        if( l2 != NULL )
        {
            tail -> next = l2;
            l1 = tail -> next;
        }

        while( l1 )
        {
            l1 -> val = l1 -> val + carry;

            carry = l1 -> val / 10;

            l1 -> val = l1 -> val % 10;

            tail = l1;
            l1 = l1 -> next;
        }


        l1 = tail;

        while( carry )
        {
            l1 -> next = new ListNode( carry );
            l1 = l1 -> next;
            carry = l1 -> val / 10;
            l1 -> val = l1 -> val % 10;
        }


        return head;
    }
};
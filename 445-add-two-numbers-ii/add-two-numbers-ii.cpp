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

    void reverseList( ListNode*& head )
    {
        ListNode* prev = nullptr, *curr = head, *next;

        while( curr )
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverseList(l1);
        reverseList(l2);

        ListNode* i = l1, *j = l2;

        ListNode* tail = nullptr;

        int carry = 0;

        while( i and j )
        {
            i -> val = i -> val + j -> val + carry;
            carry = i -> val / 10;
            i -> val %= 10;
            tail = i;
            i = i -> next;
            j = j -> next;
        }

        if( i == nullptr and j != nullptr )
        {
            tail -> next = j;
        }

        while( j )
        {
            j -> val = j -> val + carry;
            carry = j -> val / 10;
            j -> val %= 10;
            tail = j;
            j = j -> next;
        }

        while( i )
        {
            i -> val = i -> val + carry;
            carry = i -> val / 10;
            i -> val %= 10;
            tail = i;
            i = i -> next;
        }

        if( carry )
        {
            ListNode* newNode = new ListNode( carry );
            tail -> next = newNode;
            // tail = tail -> next;
        }

        reverseList(l1);

        return l1;
    }
};
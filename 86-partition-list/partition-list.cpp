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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = new ListNode(0);
        ListNode* greater_head = new ListNode(0);
        ListNode* less_ptr = less_head;
        ListNode* greater_ptr = greater_head;

        while( head )
        {
            if( head -> val < x )
            {
                less_ptr -> next = head;
                less_ptr = less_ptr -> next;
            }
            else
            {
                greater_ptr -> next = head;
                greater_ptr = greater_ptr -> next;
            }
            head = head -> next;
        }

        less_ptr -> next = greater_head -> next;
        greater_ptr -> next = NULL;

        return less_head -> next;
    }
};
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
    ListNode* middleNode(ListNode* head) {
        if( head -> next == NULL )
        {
            return head;
        }


        ListNode* fast = head, *slow = head, *prev = NULL;

        while( fast and fast -> next )
        {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }

        return slow;
    }
};
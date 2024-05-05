/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* left = node, *right = node -> next;


        while( right -> next )
        {
            left -> val = right -> val;
            left = right;
            right = right -> next;
        }

        left -> val= right -> val;
        left -> next = right -> next;

    }
};
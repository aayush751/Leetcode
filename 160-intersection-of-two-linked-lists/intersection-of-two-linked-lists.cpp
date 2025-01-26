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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* i = headA;
        ListNode* j = headB;

        while (i != j) {
            i = (i == nullptr) ? headB : i->next;
            j = (j == nullptr) ? headA : j->next;
        }

        return i;
    }
};
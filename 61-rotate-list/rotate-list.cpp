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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL )
        {
            return NULL;
        }

        if( head -> next == NULL )
        {
            return head;
        }

        int size = 0;
        ListNode* i = head;
        while( i )
        {
            size++;
            i = i -> next;
        }

        k = k % size; //ye esliye kr rhe taki k ka size list k size se exced nh kre...taki 1 place rotate hi hoga phir

        ListNode* temp = head;

        while( temp -> next )
        {
            temp = temp -> next;
        }

        temp -> next = head;

        int jump = size - k - 1;

        temp = head;

        while( jump )
        {
            temp = temp -> next;
            jump--;
        }

        ListNode* returnNode = temp -> next;
        temp -> next = NULL;

        return returnNode;
    }
};
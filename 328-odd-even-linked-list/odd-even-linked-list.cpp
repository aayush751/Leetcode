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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* dummy = dummyNode;

        ListNode* i = head;
        int cnt = 1;

        while( i )
        {
            if( cnt & 1 )
            {
                ListNode* node = new ListNode( i -> val );
                dummy -> next = node;
                dummy = dummy -> next;
            }
            cnt++;
            i = i -> next;
        }

        i = head;
        cnt = 1;

        while( i )
        {
            if( cnt % 2 == 0 )
            {
                ListNode* node = new ListNode( i -> val );
                dummy -> next = node;
                dummy = dummy -> next;
            }
            cnt++;
            i = i -> next;
        }

        ListNode* lastNode = nullptr;
        dummy -> next = lastNode;

        return dummyNode -> next;
    }
};
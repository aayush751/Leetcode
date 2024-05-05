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
    ListNode* swapNodes(ListNode* head, int k) {
        if( head -> next == NULL )
        {
            return head;
        }


        ListNode* i = head, *temp = head, *j = head; 

        int left = 0, right = 0;

        int length = 0;

        while( i )
        {
            length++;
            i = i -> next;
        }

        int last_idx = length - k;

        int cnt = 0;

        while( temp )
        {
            if( cnt == last_idx )
            {
                break;
            }

            temp = temp -> next;
            cnt++;
        }

        cnt = 0;

        while( j )
        {
            if( cnt + 1 == k )
            {
                break;
            }

            j = j -> next;
            cnt++;
        }

        int sample = temp -> val;
        temp -> val = j -> val;
        j -> val = sample;

        return head;
    }
};
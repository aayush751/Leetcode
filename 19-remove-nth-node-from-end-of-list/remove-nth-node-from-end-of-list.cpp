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
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        if( head -> next == NULL )
        {
            return NULL;
        }
        ListNode* i = head;

        int length = 0;

        while( i )
        {
            length++;
            i = i -> next;
        }

        int idx = length - n;

        if( idx == 0 )
        {
            head = head -> next;
            return head;
        }
        ListNode* temp = head, *prev = head;
        int cnt = 0;
        while( temp )
        {
            if( cnt == idx )
            {
                prev -> next = temp -> next;
                break;
            }

            if( cnt != 0 )
            {
                prev = temp;
            }
            temp = temp -> next;
            cnt++;
        }

        return head;

    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {

        if( head == nullptr or head -> next == nullptr )
        {
            return head;
        }

        ListNode* dummyNode = new ListNode(-1);
        dummyNode -> next = head;
        ListNode* prev = dummyNode;
        ListNode* curr = head, *nextNode = head -> next;

        while( nextNode )
        {
            if( curr -> val == nextNode -> val )
            {
                if( nextNode -> next != nullptr and nextNode -> next -> val != curr -> val )
                {
                    prev -> next = nextNode -> next;
                    curr = nextNode -> next;
                    nextNode = curr -> next;
                }
                else
                {
                    if( nextNode -> next == nullptr )
                    {
                        prev -> next = nextNode -> next;
                    }
                    nextNode = nextNode -> next;
                }
            }
            else
            {
                nextNode = nextNode -> next;
                prev = curr;
                curr = curr -> next;
            }
        }

        return dummyNode -> next;
    }
};
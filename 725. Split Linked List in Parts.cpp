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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
    ListNode* current = head;

  
    while (current) {
        length++;
        current = current->next;
    }

   
    int part_size = length / k;
    int larger_parts = length % k;


    vector<ListNode*> result;
    current = head;

    for (int i = 0; i < k; i++) {

        int size = part_size + (i < larger_parts ? 1 : 0);


        if (size == 0) {
            result.push_back(nullptr);
        } else {
            
            result.push_back(current);

           
            for (int j = 0; j < size - 1; j++) {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = nullptr;
            current = temp;
        }
    }

    return result;
    }
};

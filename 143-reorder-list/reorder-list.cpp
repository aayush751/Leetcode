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

//  struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// This problem can be broken down into three simple sub problems and can be solve sequentially to arrive at our final solution.
// 1. Finding the mid: take slow and fast ptr and find the start of the second half of Linked List
// 2. Reverse Linked List: reverse the second half and split the original Linked list into two independent linked list
// 3. Merge Linked List: take each node one by one from both the sublists and merge them into single linked list.

ListNode *reverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (temp != nullptr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head, *first_half = head;
    fast = fast->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *second_half = reverse(slow->next);
    slow->next = nullptr;
    while (second_half)
    {
        ListNode *temp = first_half->next, *tem = second_half->next;
        first_half->next = second_half;
        second_half->next = temp;
        first_half = temp;
        second_half = tem;
    }
    }
};
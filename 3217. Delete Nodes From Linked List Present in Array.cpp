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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set< int > st;
        for(auto i: nums )
        {
            st.insert( i );
        }

        ListNode* i = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* dummy = dummyNode;

        while( i )
        {
            if( st.find( i -> val ) == st.end() )
            {
                ListNode* newNode = new ListNode( i -> val );
                dummy -> next = newNode;
                dummy = dummy -> next;
            }
            i = i -> next;
        }

        return dummyNode -> next;
    }
};

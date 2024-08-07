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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve( vector< int >& arr, int left, int right )
    {
        if( left > right )
        {
            return nullptr;
        }

        int mid = left + ( right - left ) / 2;
        TreeNode* newNode = new TreeNode( arr[mid] );
        newNode -> left = solve( arr, left, mid - 1 );
        newNode -> right = solve( arr, mid + 1, right );

        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector< int > arr;

        ListNode* i = head;

        while( i )
        {
            arr.push_back( i -> val );
            i = i -> next;
        }

        return solve( arr, 0, arr.size() - 1 );
    }
};
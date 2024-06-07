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

    pair< bool, int > order( TreeNode* root )
    {
        // base case
        if( root == nullptr )
        {
            pair< bool, int > p = make_pair( true, 0 );
            return p;
        }

        pair< bool, int > left = order( root -> left );
        pair< bool, int > right = order( root -> right );

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs( left.second - right.second ) <= 1;

        pair< bool, int > retur;
        retur.second = max( left.second, right.second ) + 1;
        if( leftAns and rightAns and diff )
        {
            retur.first = true;
        }
        else
        {
            retur.first = false;
        }
        return retur;
    }
    bool isBalanced(TreeNode* root) {
        pair< bool, int > ans = order( root );
        return ans.first;
    }
};
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

    bool solve( TreeNode* root, long long minVal, long long maxVal )
    {
        if( root == nullptr )
        {
            return true;
        }

        if( root -> val <= minVal or root -> val >= maxVal )
        {
            return false;
        }

        bool left = solve( root -> left, minVal, root -> val );
        bool right = solve( root -> right, root -> val, maxVal );

        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        if( root -> left == nullptr and root -> right == nullptr )
        {
            return true;
        }
        return solve( root, LLONG_MIN, LLONG_MAX );
    }
};
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
    void solve( TreeNode* &a, TreeNode* &b, int level )
    {
        if( a == nullptr and b == nullptr )
        {
            return;
        }

        if( level % 2 == 1 )
        {
            swap( a -> val, b -> val );
        }

        solve( a -> left, b -> right, level + 1 );
        solve( a -> right, b -> left, level + 1 );
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if( root == nullptr )
        {
            return nullptr;
        }

        solve( root -> left, root -> right, 1 );

        return root;
    }
};
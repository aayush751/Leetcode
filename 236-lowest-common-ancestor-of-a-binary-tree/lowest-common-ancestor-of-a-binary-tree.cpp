/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if( root == nullptr )
        {
            return nullptr;
        }

        if( root -> val == p -> val )
        {
            return root;
        }
        else if( root -> val == q -> val )
        {
            return root;
        }

        TreeNode* leftAns = lowestCommonAncestor( root -> left, p, q );
        TreeNode* rightAns = lowestCommonAncestor( root -> right, p, q );

        if( leftAns == nullptr and rightAns == nullptr )
        {
            return nullptr;
        }

        if( leftAns != nullptr and rightAns == nullptr )
        {
            return leftAns;
        }

        if( leftAns == nullptr and rightAns != nullptr )
        {
            return rightAns;
        }

        return root;
    }
};
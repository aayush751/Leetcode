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
        // base case aayega yahan pr
        if( root == nullptr )
        {
            return nullptr;
        }

        if( root -> val < p -> val and root -> val < q -> val )
        {
            return lowestCommonAncestor( root -> right, p, q );
        }

        if( root -> val > p -> val and root -> val > q -> val )
        {
            return lowestCommonAncestor( root -> left, p, q );
        }

        return root;
    }
};
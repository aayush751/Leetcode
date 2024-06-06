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

    bool solve( TreeNode* lef, TreeNode* rig )
    {
        if( lef == nullptr and rig == nullptr )
        {
            return true;
        }

        if( (lef != nullptr and rig == nullptr) or (lef == nullptr and rig != nullptr) )
        {
            return false;
        }

        if( lef -> val == rig -> val )
        {
            return solve( lef -> left, rig -> right ) and solve( lef -> right, rig -> left );
        }
        else
        {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        // base case
        if( root == nullptr )
        {
            return true;
        }

        return solve( root -> left, root -> right );
    }
};
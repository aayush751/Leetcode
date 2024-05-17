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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        

        // hr ek node ek sath check krna hai taki uski waqt false kr sake
        if( p == nullptr and q == nullptr )
        {
            return true;
        }

        if( p == nullptr or q == nullptr )
        {
            return false;
        }

        if( p -> val == q -> val )
        {
            return isSameTree(p -> left, q -> left ) and isSameTree( p -> right, q -> right );
        }
        return false;
    }
};
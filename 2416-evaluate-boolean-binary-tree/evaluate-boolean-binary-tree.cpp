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
    bool evaluateTree(TreeNode* root) {
        // base case
        if( root == nullptr )
        {
            return 0;
        }

        bool left_value = evaluateTree( root -> left );
        bool right_value = evaluateTree( root -> right );

        if( root -> val ==  2 )
        {
            return left_value | right_value;
        }

        if( root -> val == 3 )
        {
            return left_value & right_value;
        }

        return ( root -> val == 0 ) ? false : true;
    }
};
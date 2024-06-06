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

    bool solve( TreeNode* node, int key, int currSum )
    {
        if( node == nullptr )
        {
            return false;
        }

        currSum += node -> val;

        if( node -> left == nullptr and node -> right == nullptr )
        {
            return currSum == key;
        }

        return solve( node -> left, key, currSum ) or solve( node -> right, key, currSum );
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        // base case 
        if( root == nullptr )
        {
            return false;
        }

        return solve( root, targetSum, 0 );
    }
};
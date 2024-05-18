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
    int count = 0;
    void order( TreeNode* node )
    {
        if( node == nullptr )
        {
            return;
        }

        count++;
        order( node -> left );
        order( node -> right );
    }
    int countNodes(TreeNode* root) {
        // int count = 0;
        order( root );
        return count;
    }
};
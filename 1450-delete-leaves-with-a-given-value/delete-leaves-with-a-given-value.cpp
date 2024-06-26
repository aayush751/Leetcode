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
    
    TreeNode* solve( TreeNode* node, int target )
    {
        // esme return krk wahi same node pr value override krna hai
        // base condtion
        if( node == nullptr )
        {
            return nullptr;
        }

        node -> left = solve( node -> left, target );
        node -> right = solve( node -> right, target );

        if( node -> left == nullptr and node -> right == nullptr  and node -> val == target )
        {
            return nullptr;
        }

        return node;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = solve( root, target );
        return root;
    }
};
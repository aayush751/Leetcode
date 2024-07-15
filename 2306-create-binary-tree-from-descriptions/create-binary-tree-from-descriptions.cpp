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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map< int, TreeNode* > mp;
        unordered_map< int, bool > hasParent;

        

        for(auto description : descriptions )
        {
            int parentValue = description[0], childValue = description[1], isLeft = description[2];
            TreeNode* parentNode = nullptr, *childNode = nullptr;

            if( mp.find(parentValue) == mp.end() ) 
            {
                parentNode = new TreeNode( parentValue );
            }
            else
            {
                parentNode = mp[parentValue];
            }

            if( mp.find( childValue) == mp.end() )
            {
                childNode = new TreeNode( childValue );
            }
            else
            {
                childNode = mp[childValue];
            }

            if( isLeft )
            {
                parentNode -> left = childNode;
            }
            else
            {
                parentNode -> right = childNode;
            }

            hasParent[childValue] = true;
            mp[childValue] = childNode;
            mp[parentValue] = parentNode;
        }

        TreeNode* rootNode = nullptr;

        for(auto& [nodeVal, node] : mp )
        {
            if( !hasParent[nodeVal] )
            {
                rootNode = node;
            }
        }

        return rootNode;
    }
};
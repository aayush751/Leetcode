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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue< TreeNode* > q;
        q.push( root );
        bool leftToRight = true;
        vector<vector<int>> ans;


        if (root == nullptr) return ans;
        
        while( !q.empty() )
        {
            int NodeCount = q.size();
            vector<int> temp( NodeCount );
            
            for(int i = 0; i < NodeCount; i++ )
            {
                TreeNode* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : NodeCount - i - 1;
                temp[index] = frontNode -> val;

                if( frontNode -> left )
                {
                    q.push( frontNode -> left );
                }

                if( frontNode -> right )
                {
                    q.push( frontNode -> right );
                }
            }
            leftToRight = !leftToRight;
            
            ans.push_back( temp );
        }

        return ans;
    }
};
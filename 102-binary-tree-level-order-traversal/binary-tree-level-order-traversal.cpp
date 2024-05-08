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

    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue< TreeNode* > q;

        if( root == NULL )
        {
            return {};
        }

        q.push( root );

        while( !q.empty() )
        {
            int size = q.size();
            vector< int > level;
            for(int i = 0; i < size; i++ )
            {
                TreeNode* temp = q.front();
                q.pop();

                if( temp != nullptr )
                {
                    level.push_back( temp -> val );
                    q.push( temp -> left );
                    q.push( temp -> right );
                }                             
            }
            if( level.size() > 0 )
            {
                ans.push_back( level );
            }
        }

        return ans;
    }
};
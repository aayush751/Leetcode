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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;

        if( root == nullptr )
        {
            return ans;
        }

        queue< TreeNode* > q;
        q.push( root );
        // stack< int > st;

        while( !q.empty() )
        {
            int size = q.size();
            
            vector< int > temp( size );

            for(int i = 0; i < size; i++ )
            {
                TreeNode* currNode = q.front();
                q.pop();

                // int index = size - i - 1;
                temp[i] = currNode -> val;

                if( currNode -> left )
                {
                    q.push( currNode -> left );
                }

                if( currNode -> right )
                {
                    q.push( currNode -> right );
                }
            }
            
            ans.insert( ans.begin(), temp );
            // st.push( 1001 );
        }


        // if( st.top() == 1001 and st.size() > 0 )
        // {
        //     st.pop();
        // }

        // while( !st.empty() )
        // {
        //     vector<int> temp1;

        //     while( st.top() != 1001 and st.empty() != 1 )
        //     {
        //         temp1.push_back( st.top() );
        //         st.pop();
        //     }

        //     if( !st.empty() )
        //     {
        //         st.pop();
        //     }
        //     ans.push_back( temp1 );
        // }

        return ans;
    }
};
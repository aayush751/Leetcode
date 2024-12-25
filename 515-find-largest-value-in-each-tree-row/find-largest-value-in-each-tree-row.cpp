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
    vector<int> largestValues(TreeNode* root) {

        if( root == nullptr )
        {
            return {};
        }
        queue< TreeNode* > que;
        que.push( root );
        
        vector< int > result;

        while( !que.empty() )
        {
            int size = que.size();
            priority_queue< int > pq;

            while( size-- )
            {
                TreeNode* frontNode = que.front();
                que.pop();

                pq.push( frontNode -> val );

                if( frontNode -> left )
                {
                    que.push( frontNode -> left );
                }

                if( frontNode -> right )
                {
                    que.push( frontNode -> right );
                }
            }
            result.push_back( pq.top() );
        }

        return result;
    }
};
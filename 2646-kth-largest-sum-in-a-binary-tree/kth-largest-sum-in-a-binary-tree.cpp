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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        if( root == nullptr )
        {
            return 0;
        }

        queue< TreeNode* > q;
        priority_queue< long long > pq;
        q.push( root );

        while( !q.empty() )
        {
            long long size =  q.size();
            long long sum = 0;
            while( size-- )
            {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr -> val;

                if( curr -> left )
                {
                    q.push( curr -> left );
                }

                if( curr -> right )
                {
                    q.push( curr -> right );
                }
            }

            pq.push( sum );
        }

        if( pq.size() < k ) return -1;

        for(size_t i = 1; i < k and pq.size() > 0 ; i++ )
        {
            pq.pop();
        }

        return pq.top();
    }
};
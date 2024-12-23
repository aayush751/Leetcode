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

    int countMinSwapsToSort( vector< int >& nums )
    {
        vector< int > sortedNums( nums.begin(), nums.end() );
        sort( begin(sortedNums), end(sortedNums) );
        int swaps = 0;

        unordered_map< int, int > mp;
        for(int i = 0; i < nums.size(); i++ )
        {
            mp[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] == sortedNums[i] )
            {
                continue;
            }

            int currIdx = mp[sortedNums[i]];
            mp[nums[i]] = currIdx;
            swap( nums[currIdx], nums[i] );
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue< TreeNode* > que;
        que.push( root );
        int result = 0;

        while( !que.empty() )
        {
            int size = que.size();
            vector< int > temp;

            while( size-- )
            {
                TreeNode* frontNode = que.front();
                que.pop();

                temp.push_back( frontNode -> val );

                if( frontNode -> left )
                {
                    que.push( frontNode -> left );
                }

                if( frontNode -> right )
                {
                    que.push( frontNode -> right );
                }
            }

            result = result + countMinSwapsToSort( temp );
        }

        return result;
    }
};
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
    
    bool solve( vector<vector<int>>& ans, vector<int> temp, TreeNode* root, int targetSum, int currSum )
    {
        if( root == nullptr )
        {
            return true;
        }
        // vector< int > temp;

        temp.push_back( root -> val );

        currSum += root -> val;

        if( root -> left == nullptr and root -> right == nullptr )
        {
            if( targetSum == currSum )
            {
                ans.push_back( temp );
            }
            else
            {
                temp.pop_back();
            }
            return targetSum == currSum;
        }

        bool left = solve(ans, temp, root -> left, targetSum, currSum );
        bool right = solve( ans, temp, root -> right, targetSum, currSum );

        return left or right;

    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        if( root == nullptr )
        {
            return ans;
        }
        solve( ans, temp, root, targetSum, 0 );

        return ans;
    }
};
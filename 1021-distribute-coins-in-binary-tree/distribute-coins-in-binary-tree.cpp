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
    int steps = 0;
    int dfs( TreeNode* node )
    {
        if( node == nullptr )
        {
            return 0;
        }

        int left_required = dfs( node -> left ); //left wale k pass agr ek value hoga toh zero value return krege agr nhi toh phir negative one return krega apne parent ko
        int right_required = dfs( node -> right ); //same with right side...agr hoga toh zero return krega ki zero required hai child ko pr aisa nhi hoga toh negative - 1krega...


        steps += abs(left_required) + abs(right_required);

        return ( node -> val - 1 ) + right_required + left_required;

    }
    int distributeCoins(TreeNode* root) {
        dfs( root );
        // ye same hai diameter of binary tree k jsa...usme diamter k sath sath height bhi calculat ekr lete the
        // ye funtion dfs return krega root node ka last value....root me last me 1 value hi rhega..q ki coin node k equal hai...
        return steps;
    }
};
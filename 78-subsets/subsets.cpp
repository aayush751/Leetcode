class Solution {
public:

    void solve( vector<int> nums, vector< int > output, int index, vector< vector< int > >& ans)
    {
        //base case
        if( index >= nums.size() )
        {
            ans.push_back( output );
            return;
        }

        // exclude case
        solve( nums, output, index + 1, ans);

        // include case
        int element = nums[index];
        output.push_back( element );
        solve( nums, output, index + 1, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< int > output;
        vector< vector< int > > ans;
        int idx = 0;
        solve(nums, output, idx, ans );
        return ans;
    }
};
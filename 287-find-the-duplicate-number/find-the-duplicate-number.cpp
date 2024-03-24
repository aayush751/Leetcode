class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector< int > ans;

        for(auto i: nums )
        {
            ans.push_back( i );
        }

        int twice = 0;

        for(int i = 0; i < ans.size(); i++ )
        {
            int idx = abs( ans[i] );

            if( ans[idx - 1 ] > 0 )
            {
                ans[idx - 1] = ans[idx  - 1] * -1;
            }
            else
            {
                twice = abs( ans[i] );
            }
        }

        return twice;
    }
};
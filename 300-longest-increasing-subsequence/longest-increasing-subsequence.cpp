class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size =  nums.size();

        vector<int> dp( size, 1e5);

        for(int i = 0; i < size; i++ )
        {
            int p = lower_bound(dp.begin(), dp.end(), nums[i] ) - dp.begin();

            if( p < size )
            {
                dp[p] = min( dp[p] , nums[i] );
            }
        }

        for(int i = size - 1; i > -1; i-- )
        {
            if( dp[i] < 1e5 )
            {
                return i + 1;
            }
        }

        return 0;
    }
};
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {

        sort( begin( nums), end(nums) );

        int n = nums.size();
        int median = nums[n / 2];

        if( median == k )
        {
            return 0;
        }

        long long cnt = 0;


        if( median > k )
        {
            for(int i = n / 2; i > -1; i-- )
            {
                cnt += max(0, nums[i] - k );
            }
        }
        else
        {
            for(int i = n / 2; i < n; i++ )
            {
                cnt += max( 0 , k - nums[i] );
            }
        }

        return cnt;
    }
};
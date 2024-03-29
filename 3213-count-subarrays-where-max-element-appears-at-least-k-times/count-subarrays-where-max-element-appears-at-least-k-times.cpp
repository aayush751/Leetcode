class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long left = 0, cnt = 0, ans = 0;

        long long maxi = -1;

        for( auto i: nums )
        {
            if( i > maxi )
            {
                maxi = i;
            }
        }

        for(int right = 0; right < nums.size(); right++ )
        {
            if( nums[right] == maxi )
            {
                cnt++;
            }

            while( cnt >= k )
            {
                ans += (long long)( nums.size() - right);
                if( nums[left] == maxi )
                {
                    cnt--;
                }
                left++;
            }

        }

        return ans;
    }
};
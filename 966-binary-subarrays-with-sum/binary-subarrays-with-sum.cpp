class Solution {
public:


    int atmost( vector<int>& nums, int goal )
    {
        int left = 0, right = 0, sum = 0;

        int ans = 0;

        for( ; right < nums.size(); right++ )
        {
            sum += nums[right];

            while( sum > goal and left <= right )
            {
                sum -= nums[left];
                left++;
            }
            
            ans += right - left + 1;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost( nums, goal ) - atmost( nums, goal - 1 );
    }
};
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long lastOccu = -1;
        long long ans = 0;

        for(int i = 0; i < nums.size(); i++ )
        {
            if( i > 0 and nums[i] == nums[i - 1] )
            {
                lastOccu = i - 1;
            }

            ans = ans + ( i - lastOccu );
        }

        return ans;
    }
};
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sbse phle sort kregein taki sb line me aa jaye

        sort( begin(nums), end(nums) );

        int ans = 0;

        for(int i = 1; i < nums.size(); i++ )
        {
            if( nums[i - 1] == nums[i] )
            {
                ans = ans + abs( nums[i] - nums[i - 1] ) + 1;
                nums[i] = nums[i] + abs( nums[i] - nums[i - 1] ) + 1;
            }
            else if( nums[i - 1] > nums[i] )
            {
                ans = ans + abs( nums[i] - nums[i - 1] ) + 1;
                nums[i] = nums[i] + abs( nums[i] - nums[i - 1] ) + 1;
            }
        }

        return ans;
    }
};
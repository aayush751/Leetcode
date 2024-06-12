class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // sbse phle bina space wla approach lengein...
        // esme kya krna hai jo valid number( negative number ) nhi hai usko n +1 se replace kr dena hai

        int n = nums.size();

        for(int i = 0; i < n; i++ )
        {
            if( nums[i] <= 0 )
            {
                nums[i] = n + 1;
            }
        }

        for( int i = 0; i < n; i++ )
        {
            if( abs( nums[i] ) <= n and nums[abs(nums[i]) - 1] > 0 )
            {
                nums[ abs(nums[i]) - 1 ] = nums[ abs(nums[i]) - 1 ] * -1;
            }
        }

        for(int i = 0; i < n; i++ )
        {
            if( nums[i] > 0 )
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxi = INT_MIN;

        if( nums.size() == 1 )
        {
            return true;
        }
        
        if( nums.size() >= 3 )
        {
            for(int i = 0; i < nums.size() - 2; i++ )
        {
            maxi = max( maxi, nums[i] );

            if( maxi > nums[i + 2] )
            {
                return false;
            }
        }
        }

        return true;
    }
};
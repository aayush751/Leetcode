class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )
        {
            return 1;
        }

        for(int i = 0; i < n - 1; i++ )
        {
            if( nums[i] != nums[i + 1] and (nums[i] % 2 == 0 and nums[i + 1] % 2 == 1) or (nums[i] % 2 == 1 and nums[i + 1] % 2 == 0) )
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
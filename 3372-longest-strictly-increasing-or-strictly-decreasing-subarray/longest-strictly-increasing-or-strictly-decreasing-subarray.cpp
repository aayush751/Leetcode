class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int currLength = 1, maxLength = 1;

        for(int i = 1; i < nums.size(); i++ )
        {
            // for strictly increasing subarray count
            if( nums[i - 1] < nums[i] )
            {
                currLength++;
                maxLength = max( maxLength, currLength );
            }
            else
            {
                currLength = 1;
            }
        }

        currLength = 1;

        for(int i = 1; i < nums.size(); i++ )
        {
            if( nums[i -1] > nums[i] )
            {
                currLength++;
                maxLength = max( maxLength, currLength );
            }
            else
            {
                currLength = 1;
            }
        }

        return maxLength;
    }
};
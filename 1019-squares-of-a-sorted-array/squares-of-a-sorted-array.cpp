class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector< int > ans( size );

        int i = 0, j = size - 1;

        int k = size - 1;
        while( i < j )
        {
            if( abs( nums[i] ) <= abs( nums[j]) )
            {
                ans[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                ans[k--] = nums[i] * nums[i];
                i++;
            }
        }

        if( j <= i )
        {
            ans[k] = nums[j] * nums[j];
        }

        return ans;
    }
};
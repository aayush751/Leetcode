class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int plus = 0, minus = 1;

        int size = nums.size();

        vector< int > ans( size );

        for(int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] > 0 )
            {
                ans[plus] = nums[i];
                plus += 2;
            }
            else
            {
                ans[minus] = nums[i];
                minus += 2;
            }
        }

        return ans;
    }
};
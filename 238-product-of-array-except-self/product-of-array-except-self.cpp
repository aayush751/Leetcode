class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector< int > ans( size );

        ans[0] = 1;

        for(int i = 1; i < size; i++ )
        {
            ans[i] = nums[i - 1] * ans[i - 1]; 
        } 

        int r = 1;

        for(int i = size - 1; i > -1; i-- )
        {
            ans[i] = ans[i] * r;
            r = r * nums[i];
        }

        return ans;
    }
};
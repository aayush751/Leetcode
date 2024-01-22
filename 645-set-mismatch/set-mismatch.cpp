class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int twice = 0;
        int ori = 0;

        for(int i = 0; i < n; i++ )
        {
            if( v[nums[i] - 1] == 0 )
            {
                v[nums[i] - 1] = 1;
            }
            else
            {
                twice = nums[i];
            }
        }

        for(int i = 0; i < n; i++ )
        {
            if( v[i] == 0 )
            {
                ori = i + 1;
                break;
            }
        }

        return {twice, ori};
    }
};
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(begin(nums), end(nums) );
        int n = nums.size();
        vector<int> ans(n);

        int alice = 1;
        int bob = 0;
        int flag = false;
        for(int i = 0; i < n; i++ )
        {
            if( flag == true )
            {
                ans[bob] = nums[i];
                bob += 2;
            }
            else
            {
                ans[alice] = nums[i];
                alice+= 2;
            }
            flag = !flag;
        }

        return ans;
    }
};
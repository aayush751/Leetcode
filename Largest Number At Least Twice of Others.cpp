class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++ )
        {
            mp[i] = nums[i];
        }
        int k = 0;
        for(int i = 0; i < nums.size(); i++ )
        {
            if(mp[i] == max )
            {
                k = i;
                continue;
            }
            if(mp[i] * 2 > max )
            {
                return -1;
            }
        }

        return k;
    }
};

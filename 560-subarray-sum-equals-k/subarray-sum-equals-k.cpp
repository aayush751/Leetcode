class Solution {
public:
    int subarraySum(vector<int>& nums, int goal ) {
        int prefix_sum = 0;
        unordered_map< int , int > mp;
        mp[0] = 1;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++ )
        {
            prefix_sum += nums[i];

            if( mp.find( prefix_sum - goal ) != mp.end() )
            {
                ans += mp[prefix_sum - goal];
            }

            mp[prefix_sum]++;
        }

        return ans;
    }
};
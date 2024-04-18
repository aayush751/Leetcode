class Solution {
public:

    int atmost( vector<int>& nums, int goal );

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefix = 0;
        int ans = 0;

        unordered_map< int , int > mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++ )
        {
            prefix += nums[i];

            if( mp.find( prefix - goal ) != mp.end() )
            {
                ans += mp[prefix - goal];
            }

            mp[prefix]++;
        }

        return ans;
    }
};
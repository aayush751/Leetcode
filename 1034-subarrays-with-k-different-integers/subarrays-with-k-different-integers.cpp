class Solution {
public:

    int atmost(vector<int>& nums, int k)
    {
        int left = 0, ans = 0;
        unordered_map< int, int > mp;

        for(int right = 0; right < nums.size(); right++ )
        {
            mp[nums[right]]++;

            while( mp.size() > k )
            {
                mp[nums[left]]--;
                if( mp[nums[left]] == 0 )
                {
                    mp.erase( nums[left] );
                }
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost( nums, k ) - atmost( nums, k - 1 );
    }
};
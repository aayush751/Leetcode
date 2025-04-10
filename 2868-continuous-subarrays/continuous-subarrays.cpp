class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        map< int, int > mp;
        
        long long count = 0;

        while( j < n )
        {
            mp[nums[j]]++;

            while( abs( mp.rbegin() -> first - mp.begin() -> first ) > 2 )
            {
                mp[nums[i]] -= 1;
                if( mp[nums[i]] == 0 )
                {
                    mp.erase( nums[i] );
                }
                i++;
            }

            count += j - i + 1;
            j++;
        }
        return count;
    }
};
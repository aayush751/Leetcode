class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;


        for(int i = 0; i < nums.size(); i++ )
        {
            
            mp[nums[i]]++;
        }
        
        int ans = 0;

        for(auto i: mp)
        {
            if( i.second == 1 )
            {
                return -1;
            }
            else if( i.second % 3 == 0 )
            {
                ans += i.second / 3;
                // To empty the array with less operations, we'll select three elements.
                // By dividing the no's frequency by 3, we can get 0, 1 or 2 as a remainder.
                // using extension new features
            }
            else
            {
                int value =  i.second;

                // Here either the remainder will be 1 or 2;
                // Take example as 14 - 10 times;
                //  and 12 - 9 times;

                ans += value / 3;

                value = value % 3;

                if( value == 1 )
                {
                    ans--;
                    value += 3;
                }

                ans += value / 2;
            }            
        }

        return ans;
    }
};
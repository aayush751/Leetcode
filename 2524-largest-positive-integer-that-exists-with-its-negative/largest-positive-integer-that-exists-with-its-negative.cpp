class Solution {
public:
    int findMaxK(vector<int>& nums) {

        unordered_map< int , int > mp;
        int maxi= INT_MIN;
        for(int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] < 0 )
            {
                int value = abs( nums[i] );

                if( mp.find( value ) == mp.end() )
                {
                    mp[nums[i]]++;
                }
                else
                {
                    if( value > maxi )
                    {
                        maxi = value;
                    }
                }
            }
            else
            {
                int nega = nums[i] * - 1;
                if( mp.find( nega ) == mp.end() )
                {
                    mp[nums[i]]++;
                }
                else
                {
                    if( nums[i] > maxi )
                    {
                        maxi = nums[i];
                    }
                }
            }
        }

        if( maxi == INT_MIN ? maxi = -1 : maxi );
        return maxi;
    }
};
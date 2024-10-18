class Solution {
public:

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;

        for(int num : nums )
        {
            maxOr |= num;
        }

        function< void( int, int ) > dfs = [&]( int idx, int currOr )
        {
            if( currOr == maxOr )
            {
                count++;
            }

            for(int i = idx; i < nums.size(); i++ )
            {
                dfs( i + 1, currOr | nums[i] );
            }
        };

        dfs( 0, 0 );

        return count;
    }
};
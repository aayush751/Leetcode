class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;
        int minIndex = n;

        vector< pair< int, int > > vp;

        for(int i = 0; i < nums.size(); i++ )
        {
            vp.push_back( { nums[i], i } );
        }

        sort( vp.begin(), vp.end() );

        for( auto& [val, index]: vp )
        {
            maxWidth = max( maxWidth, index - minIndex );
            minIndex = min( minIndex, index );
        }

        return maxWidth;
    }

};
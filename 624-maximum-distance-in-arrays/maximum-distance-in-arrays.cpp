class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int tillSmall = arrays[0][0];
        int tillLarge = arrays[0].back();
        int ans = 0;

        for(int i = 1; i < arrays.size(); i++ )
        {
            ans = max( ans, abs(tillSmall - arrays[i].back() ) );

            ans = max( ans, abs( tillLarge - arrays[i][0] ) );

            tillSmall = min( tillSmall, arrays[i][0] );
            tillLarge = max( tillLarge, arrays[i].back());
        }

        return ans;
    }
};
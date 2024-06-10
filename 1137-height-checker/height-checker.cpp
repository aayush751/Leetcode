class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector< int > heightsCopy(heights);

        sort( begin(heights), end(heights) );

        int ans = 0;

        for(int i = 0; i < heights.size(); i++ )
        {
            if( heights[i] != heightsCopy[i] )
            {
                ans++;
            }
        }

        return ans;
    }

};
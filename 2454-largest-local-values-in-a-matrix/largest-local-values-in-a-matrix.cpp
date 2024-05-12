class Solution {
public:

    int findMaxValue( vector<vector<int>>& grid, int i, int j )
    {
        int n = grid.size();
        int maxValue = INT_MIN;
        for(int r = i; r < i + 3; r++ )
        {
            for(int c = j; c < j + 3; c++ )
            {
                if( grid[r][c] > maxValue )
                {
                    maxValue = grid[r][c];
                }
            }
        }

        return maxValue;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int r = n - 2, c = n - 2;
        vector< vector< int > > ans( r, vector< int > (c, 0) );

        for(int i = 0; i < n - 2; i++ )
        {
            for(int j = 0; j < n - 2; j++ )
            {
                ans[i][j] = findMaxValue( grid, i, j );
            }
        }

        return ans;
    }
};
class Solution {
public:


    vector< int > dx = {-1, 0, 0, 1};
    vector< int > dy = {0, -1, 1, 0};
    int dfs(int i, int j, vector<vector<int>>& grid )
    {
        int r = grid.size(), c = grid[0].size();
        if( i < 0 or i >= r or j < 0 or j >= c or grid[i][j] == 0 )
        {
            return 0;
        }

        int max_Sum = 0, curVal = grid[i][j];
        for(int d = 0; d < 4; d++ )
        {
            int ni = i + dx[d], nj = j + dy[d];
            grid[i][j] = 0;
            max_Sum = max( max_Sum, curVal + dfs(ni, nj, grid) );
            grid[i][j] = curVal;
        }
        return max_Sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        int ans = 0;
        for(int i = 0; i < r; i++ )
        {
            for(int j = 0; j < c; j++ )
            {
                if( grid[i][j] != 0 )
                {
                    ans = max( ans, dfs(i, j, grid) );
                }
            }
        }

        return ans;
    }
};
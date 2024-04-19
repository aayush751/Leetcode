class Solution {
public:
    int n = 0;
    int m = 0;

    void dfs( vector<vector<char>>& grid, int i, int j )
    {
        if( i < 0 or i >= n or j < 0 or j >= m )
        {
            return;
        }

        // water ho ya check kia hua cell ho
        if( grid[i][j] == '0' or grid[i][j] == '2' )
        {
            return;
        }
        grid[i][j] = '2';
        dfs(grid, i - 1, j );
        dfs(grid, i, j - 1 );
        dfs(grid, i, j + 1 );
        dfs(grid, i + 1, j );
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;
        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < m; j++ )
            {
                if( grid[i][j] == '1' )
                {
                    dfs( grid,i,j );
                    count++;
                }
            }
        }

        return count;
    }
};
class Solution {
public:

    bool dfs( vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n )
    {
        // check kro ki boundary k bhr hain ya visited hai
        if( i < 0 or j < 0 or i >= m or j >= n or grid2[i][j] == 0 )
        {
            return true;
        }

        // grid1 me wo i,j index wala cell water ho
        if( grid1[i][j] == 0 )
        {
            return false;
        }

        // ab aisa kch nhi hai toh usko mark kro ki wo cell grid2 wala visited ho gya hai
        grid2[i][j] = 0;

        bool up = dfs( grid1, grid2, i - 1, j, m, n ); // current cell k uper wala plot dekh rhe hain ki kya hai wo
        bool down = dfs( grid1, grid2, i + 1, j, m, n); //current cell k niche wala plot dekh rhe hain ki kya hai wo
        bool left = dfs( grid1, grid2, i, j - 1, m, n ); //current cell k left side wlaa plot dekh rhe hain
        bool right = dfs( grid1, grid2, i, j + 1, m, n ); //current cell k right side wala plot dekh rhe hain

        return up and down and left and right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // es question me ye hai ki grid2 me jahan jahan island hai same jgh me grid1 me land hai ya nhi..agr nhi toh phir wo subisland nhi hai

        int m = grid1.size();
        int n = grid1[0].size();
        int subIslandCount = 0;

        for(int i = 0; i < m; i++ )
        {
            for(int j = 0; j < n; j++ )
            {
                if( grid2[i][j] == 1 )
                {
                    if ( dfs(grid1, grid2, i, j, m, n) ) 
                    {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};
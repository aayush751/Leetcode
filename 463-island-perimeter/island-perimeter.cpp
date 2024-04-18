class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int up, down, left, right;

        int row = grid.size(), col = grid[0].size(), ans = 0;

        for(int r = 0; r < row; r++ )
        {
            for(int c = 0; c < col; c++ )
            {
                if( grid[r][c] == 1 )
                {
                    // for up part of cell
                    if( r == 0 ) up = 1;   
                    else up = grid[r - 1][c] == 0;
                    
                    // for left side/part of cell
                    if( c == 0 ) left = 1;
                    else left = grid[r][c - 1] == 0;

                    // for down side/ part of cell
                    if( r == row - 1 ) down = 1;
                    else down = grid[r + 1][c] == 0;

                    // for right side/part of cell
                    if( c == col - 1 ) right = 1;
                    else right = grid[r][c + 1] == 0;

                    ans = ans + up + left + down + right;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool isMagic( vector<vector<int>>& grid, int r, int c )
    {
        set< int > values;
        int s = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // hr row ko check kro
        for(int i = 0; i < 3; i++ )
        {
            int rowSum = grid[r + i][c] + grid[r + i][c + 1] + grid[i + r][c + 2];
            values.insert( grid[r + i][c] );
            values.insert( grid[r + i][c + 1] );
            values.insert( grid[i + r][c + 2] );

            if( rowSum != s )
            {
                return false;
            }
        }

        // ab column check kro
        for(int j = 0; j < 3; j++ )
        {
            int colSum = grid[r][j + c] + grid[r + 1][j + c] + grid[r + 2][j + c];
            values.insert( grid[r][j + c] );
            values.insert( grid[r + 1][j + c] );
            values.insert( grid[r + 2][j + c] );

            if( colSum != s )
            {
                return false;
            }
        }

        // ab diagonal element check kro
        int diag1Sum = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int diga2Sum = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        
        if( diag1Sum != s or diga2Sum != s ) return false;

        // agr ye sb true nikla phir values check kro
        if( values.size() == 9 and *values.begin() >= 1 and *values.rbegin() <= 9 )
        {
            return true;
        }

        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int r = 0; r <= row - 3; r++ )
        {
            for(int c = 0; c <= col - 3; c++ )
            {
                if( isMagic(grid, r, c ) )
                {
                    count++;
                }
            }
        }

        return count;
    }
};
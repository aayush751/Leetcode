class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // sbse phle equal rows and inverted equal rows find krna hai

        int maxRows = 0;

        for( auto& currRows: matrix )
        {
            vector< int > inverted(n);

            for(int col = 0; col < n; col++ )
            {
                inverted[col] = currRows[col] == 0 ? 1 : 0;
            }

            int count = 0;

            for( auto& rows: matrix )
            {
                if( rows == currRows or rows == inverted )
                {
                    count++;
                }
            }

            maxRows = max( maxRows, count );
        }

        return maxRows;
    }
};
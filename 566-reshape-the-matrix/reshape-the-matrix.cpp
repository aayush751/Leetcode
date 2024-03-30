class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        vector<vector<int>> v( r, vector<int> (c, 0));

        int ori_r = mat.size();
        int ori_c = mat[0].size();

        if( r * c != ori_r * ori_c )
        {
            return mat;
        }
        int row = 0, col = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                v[i][j] = mat[row][col++];
                if( col == ori_c )
                {
                    row++;
                    col = 0;
                }
            }
        }

        return v;


    }
};
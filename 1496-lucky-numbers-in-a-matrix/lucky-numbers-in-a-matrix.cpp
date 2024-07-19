class Solution {
public:

    bool check( vector<vector<int>>& matrix, int key, int i, int j )
    {
        bool flag_row = true;
        bool flag_col = true;

        for(int k = 0; k < matrix[0].size(); k++ )
        {
            if( key > matrix[i][k] )
            {
                flag_row = false;;
                break;
            }
        }

        for(int k = 0; k < matrix.size(); k++ )
        {
            if( key < matrix[k][j] )
            {
                flag_col = false;
                break;
            }
        }

        return flag_row and flag_col;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++ )
        {
            for(int j = 0; j < matrix[0].size(); j++ )
            {
                if( check( matrix, matrix[i][j], i, j ) )
                {
                    return { matrix[i][j] };
                }
            }
        }

        return {};
    }
};
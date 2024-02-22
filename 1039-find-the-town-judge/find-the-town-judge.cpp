class Solution {
public:
    int findJudge(int n, vector<vector<int>>& tru) {
        vector< int > out( n + 1 );
        vector< int > in( n + 1 );

        int out_degree = 0, in_degree = n - 1;

        for(int i = 0; i < tru.size(); i++ )
        {
            out[tru[i][0]]++;
            in[tru[i][1]]++;
        }

        for(int i = 1; i<=n; i++ )
        {
            if( out[i] == out_degree and in[i] == in_degree )
            {
                return i;
            }
        }

        return -1;
    }
};
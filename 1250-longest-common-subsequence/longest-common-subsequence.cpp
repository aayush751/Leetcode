class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();

        int dp[n + 1][m + 1];

        for(int i = 0; i < m + 1; i++ )
        {
            dp[n][i] = 0;
        }

        for(int i = 0; i < n; i++ )
        {
            dp[i][m] = 0;
        }

        for(int i = n - 1; i  > -1; i-- )
        {
            for(int j = m - 1; j > -1; j-- )
            {
                if( a[i] == b[j] )
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max( dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
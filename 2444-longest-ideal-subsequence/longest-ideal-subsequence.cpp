class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans = 0;
        int max_length = 0;
        vector< int > dp(26, 0);

        for(int i = 0; i < s.size(); i++ )
        {
            max_length = 0;
            for(char last = 'a'; last <= 'z'; last++ )
            {
                if( abs( s[i] - last ) <= k )
                {
                    max_length = max( max_length, 1 + dp[last - 'a'] );
                }
            }
            dp[s[i] - 'a'] = max_length;
            ans = max( ans, max_length );
        }

        return ans;
        
    }
};
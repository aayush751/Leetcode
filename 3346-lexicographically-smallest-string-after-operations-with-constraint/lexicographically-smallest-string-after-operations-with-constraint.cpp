class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string ans = s;
        
        for(int i = 0; i < n; i++ )
        {
            int min_dis = 0;
            for(char ch = 'a'; ch <= 'z'; ch++ )
            {
                min_dis = min( abs(s[i] - ch), 26 - abs( s[i] - ch ) );
                
                if( min_dis <= k )
                {
                    k = k - min_dis;
                    ans[i] = ch;
                    break;
                }
            }
        }
        
        return ans;
    }
};
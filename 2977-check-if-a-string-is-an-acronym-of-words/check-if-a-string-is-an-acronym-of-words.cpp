class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        

        int cnt = 0;

        int i = 0;
        while( i < words.size() and i < s.size() )
        {
            if( words[i][0] == s[i] )
            {
                cnt++;
            }
            i++;
        }

        if( cnt == s.size() and cnt == words.size() )
        {
            return true;
        }

        return false;
        
    }
};
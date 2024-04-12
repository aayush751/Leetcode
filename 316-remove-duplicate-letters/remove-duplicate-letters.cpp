class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector< int > lastIndex(26, 0 );
        vector< char > Taken(26, false );


        string ans = "";

        for(int i = 0; i < s.size(); i++ )
        {
            char ch = s[i];

            lastIndex[ch - 'a'] = i;
        }

        for(int i = 0; i < s.size(); i++ )
        {
            char x = s[i];

            if( Taken[x - 'a'] == true )
            {
                continue;
            }

            while( ans.size() > 0 and ans.back() > s[i] and lastIndex[ans.back() - 'a'] > i )
            {
                Taken[ans.back() - 'a'] = false;
                ans.pop_back(); 
            }

            ans = ans + s[i];
            Taken[x - 'a'] = true;
        }

        return ans;
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector <string> ans;
        string st;
        unordered_map <char , int > mp;
        unordered_map <string , int > v;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] != 32 )
            {
                st = st + s[i]; 
            }
            else
            {
                ans.push_back(st);
                st = "";
            }
        }

        ans.push_back( st );
        if( ans.size() != pattern.size() )
        {
            return false;
        }

        for(int i = 0; i < pattern.size(); i++ )
        {
            if( mp[pattern[i]] != v[ans[i]] )
            {
                return false;
            }
            else
            {
                mp[pattern[i]] = v[ans[i]] = i + 1;
            }
        }
        return 1 ;
        

    }
};
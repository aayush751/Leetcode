class Solution {
public:
    int countSegments(string s) {
        vector< string > v;

        string ans;

        for(int i = 0; i < s.size(); i++)
        {
            if( s[i] == 32 )
            {
                if( ans.size() > 0 )
                {
                    v.push_back( ans );
                    ans = "";
                }
                continue;
            }
            else
            {
                ans = ans + s[i];
            }
        }

        if( ans.size() > 0 )
        {
            v.push_back( ans );
        }

        return v.size();
    }
};
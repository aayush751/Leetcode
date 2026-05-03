class Solution {
public:

    bool solve( string s, string goal, int i )
    {
        if( s == goal )
        {
            return true;
        }

        if( i == s.size() )
        {
            return false;
        }

        char ch = s[0];

        for(int j = 1; j < s.size(); j++ )
        {
            s[j - 1] = s[j];
        }

        int n = s.size();
        s[n - 1] = ch;

        return solve( s, goal, i + 1 );
    }
    bool rotateString(string s, string goal) {
        int i = 0;
        return solve( s, goal, 0 );
    }
};
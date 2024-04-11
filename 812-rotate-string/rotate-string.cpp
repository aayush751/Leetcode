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

        char x = s[0];
        for(int i = 1; i < s.size(); i++ )
        {
            s[i - 1] = s[i];
        }

        int n = s.size();
        s[n - 1] = x;
        return solve( s, goal, i + 1 );
    }


    bool rotateString(string s, string goal) {
        bool ans = solve( s, goal, 0 );
        return ans;
    }
};
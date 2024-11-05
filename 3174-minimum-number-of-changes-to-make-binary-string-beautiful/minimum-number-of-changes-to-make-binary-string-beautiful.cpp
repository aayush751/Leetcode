class Solution {
public:
    int minChanges(string s) {
        int change = 0;
        int count = 0;

        char ch = s[0];

        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == ch )
            {
                count++;
                continue;
            }

            if( count % 2 == 0 )
            {
                count = 1;
            }
            else
            {
                change++;
                count = 0;
            }

            ch = s[i];
        }

        return change;
    }
};
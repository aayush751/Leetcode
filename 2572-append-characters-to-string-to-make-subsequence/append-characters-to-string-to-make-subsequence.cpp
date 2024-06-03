class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1 = s.size(), n2 = t.size();

        int i = 0, j = 0;

        while( i < n1 and j < n2 )
        {
            if( s[i] == t[j] )
            {
                i++;
                j++;
                continue;
            }
            else
            {
                i++;
            }
        }

        return t.size() - j;
    }
}; 
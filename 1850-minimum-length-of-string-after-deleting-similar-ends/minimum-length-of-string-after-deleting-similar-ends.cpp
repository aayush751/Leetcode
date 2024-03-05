class Solution {
public:
    int minimumLength(string str) {
        int n = str.size();
        int p = 0, s = n - 1;

        while( p < s and str[p] == str[s] )
        {
            char ch = str[p];

            while( p <= s and str[p] == ch )
            {
                p++;
            }

            while( p <= s and str[s] == ch )
            {
                s--;
            }
        }

        return s - p + 1;
    }
};
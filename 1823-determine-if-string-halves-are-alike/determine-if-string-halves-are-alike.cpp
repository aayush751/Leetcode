class Solution {
public:
    bool halvesAreAlike(string s) {
        // unordered_map<int, int> a,b;
        int cnt_1 = 0, cnt_2 = 0;

        int size = s.size();

        int i = 0, j = size/2;

        while( i < size/2 )
        {
            if( s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' )
            {
                cnt_1++;
            }
            if( s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u' or s[j] == 'A' or s[j] == 'E' or s[j] == 'I' or s[j] == 'O' or s[j] == 'U' )
            {
                cnt_2++;
            }
            i++;
            j++;
        }

        if( cnt_1 != cnt_2 )
        {
            return false;
        }

        return true;
    }
};
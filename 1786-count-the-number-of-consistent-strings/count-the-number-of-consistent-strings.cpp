class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector< int > freq(26, 0);

        for(int i = 0; i < allowed.size(); i++ )
        {
            freq[allowed[i] - 'a']++;
        }

        int count = 0;
        bool flag = false;
        for( string& s: words )
        {
            for( char& ch: s )
            {
                if( freq[ch - 'a'] == 0 )
                {
                    flag = true;
                    break;
                }
            }

            if( flag == false )
            {
                count++;
            }
            else
            {
                flag = false;
            }
        }

        return count;
    }
};
class Solution {
public:


    bool ok( string s, int len )
    {
        int n = s.size();
        int freq[26] ={0};

        for(int i = 0; i < len; i++ )
        {
            freq[s[i] - 'a']++;
        }

        for(int i = len; i < n; i += len)
        {
            int rangefreq[26] = {0};
            
            for(int j = i; j < i + len; j++ )
            {
                rangefreq[s[j] - 'a']++;
            }

            for(int j = 0; j < 26; j++ )
            {
                if( freq[j] != rangefreq[j] )
                {
                    return false;
                }
            }
        }

        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();

        for(int i = 1; i <= n; i++ )
        {
            if( n % i == 0 and ok(s, i) )
            {
                return i;
            }
        }

        return n;
    }
};
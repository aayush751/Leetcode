class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();

        if( n == k ) return true;

        if( n < k ) return false;

        vector< int > freqCount( 26, 0 );

        for( auto characters: s )
        {
            freqCount[characters - 'a']++;
        }

        int oddFreqCharCount = 0;

        for( int i = 0; i < 26; i++ )
        {
            if( freqCount[i] % 2 == 1 )
            {
                oddFreqCharCount++;
            }
        }

        return oddFreqCharCount <= k;
    }
};
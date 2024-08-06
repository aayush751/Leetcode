class Solution {
public:
    int minimumPushes(string word) {
        // calculating frequencies of every characters
        unordered_map< char, int > mp;

        for( char& ch: word )
        {
            mp[ch]++;
        }

        // storing frequency in descending order in a vector
        vector< int > v;

        for( auto i: mp )
        {
            v.push_back( i.second );
        }

        // sorting v element in descending order
        sort( v.begin(), v.end(), greater<int>() );

        int ans = 0;
        int row_count = 0;

        // now calculating presses
        for( int& freq: v )
        {
            row_count++;
            if( row_count <= 8 )
            {
                ans = ans + 1 * freq;
            }
            else if( row_count > 8 and row_count <= 16 )
            {
                ans = ans + 2 * freq;
            }
            else if( row_count > 16 and row_count <= 24 )
            {
                ans = ans + 3 * freq;
            }
            else
            {
                ans = ans + 4 * freq;
            }
        }

        return ans;
    }
};
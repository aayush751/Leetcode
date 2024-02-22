class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map< int, int > mp;


        vector< int > freq;
        for( auto i: arr )
        {
            mp[i]++;
        }

        for( auto i: mp )
        {
            freq.push_back( i.second );
        }

        sort( begin(freq), end(freq) );

        int i;
        for( i = 0; i < freq.size(); i++ )
        {
            if( k > 0 )
            {
                k = k - freq[i];
            }
            else
            {
                break;
            }
        }

        if( k <  0 )
        {
            return freq.size() - i + 1;
        }

        return freq.size() - i;
    }
};
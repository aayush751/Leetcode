class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map< int, int > mp;
        vector< vector< int > > v;
        for(auto i: items1 )
        {
            if( mp.find( i[0] ) != mp.end() )
            {
                mp[ i[0] ] = mp[ i[0] ] + i[1];
            }
            else
            {
                mp[ i[0] ] = i[1];
            }
        }

        for( auto i: items2 ) 
        {
            if( mp.find( i[0] ) != mp.end() )
            {
                mp[ i[0] ] = mp[ i[0] ] + i[1];
            }
            else
            {
                mp[ i[0] ] = i[1];
            }
        }

        for( auto itr = mp.begin(); itr != mp.end(); itr++ )
        {
            v.push_back( {itr -> first, itr -> second} );
        }

        return v;
    }
};
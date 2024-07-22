class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector< pair< int, string > > v;
        int n = names.size();

        for(int i = 0; i < n; i++ )
        {
            v.push_back( {heights[i], names[i]} );
        }

        sort( begin(v), end(v) );

        vector< string > ans;

        for( auto it = v.rbegin(); it != v.rend(); it++ )
        {
            ans.push_back( it -> second );
        }

        return ans;
    }
};
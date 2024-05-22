class Solution {
public:

    bool palin( const string& s, int start, int end )
    {
        while( start <= end )
        {
            if( s[start++] != s[end--] )
            {
                return false;
            }
        }
        return true;
    }

    void dfs( int index, string& s, vector< string >& path, vector< vector < string > >& ans )
    {
        if( index == s.size() )
        {
            ans.push_back( path );
            return; 
        }

        for(int end = index; end < s.size(); end++ )
        {
            if( palin(s, index, end ) )
            {
                path.push_back(s.substr(index, end - index + 1) );
                dfs( end + 1, s, path, ans );
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector< vector< string > > ans;
        if( s.empty() )
        {
            return ans;
        }

        vector< string > path;

        dfs( 0, s, path, ans );

        return ans;
    }
};
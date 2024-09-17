class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        istringstream as1( s1 );
        istringstream as2( s2 );

        string str1, str2;

        vector< string > v1, v2;
        unordered_map< string, int > mps1, mps2;
        while( as1 >> str1 )
        {
            v1.push_back( str1 );
        }

        while( as2 >> str2 )
        {
            v2.push_back( str2 );
        }

        for(auto i: v1 )
        {
            mps1[i]++;
        }

        for(auto i: v2 )
        {
            mps2[i]++;
        }

        vector< string > ans;

        for(int i = 0; i < v1.size(); i++ )
        {
            if( mps1[v1[i]] == 1 )
            {
                if( mps2.find( v1[i] ) == mps2.end() )
                {
                    ans.push_back( v1[i] );
                }
            }
        }

        for(int i = 0; i < v2.size(); i++ )
        {
            if( mps2[v2[i]] == 1 )
            {
                if( mps1.find( v2[i] ) == mps1.end() )
                {
                    ans.push_back( v2[i] );
                }
            }
        }

        return ans;
    }
};
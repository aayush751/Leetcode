class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream as1(s1);
        istringstream as2(s2);

        string ans1, ans2;
        unordered_map< string, int > mp, mp2;

        vector< string > v1, v2;
        
        while( as1 >> ans1 )
        {
            v1.push_back( ans1 );
        }

        while( as2 >> ans2 )
        {
            v2.push_back( ans2 );
        }

        for(auto i: v1 )
        {
            mp[i]++;
        }

        for(auto i: v2 )
        {
            mp2[i]++;
        }

        vector< string > ans;
        for(int i = 0; i < v2.size(); i++ )
        {
            if( mp2[v2[i]] == 1 )
            {
                if( mp.find( v2[i] ) == mp.end() )
                {
                    ans.push_back( v2[i] );
                }
            }
        }

        for(int i = 0; i < v1.size(); i++ )
        {
            if( mp[v1[i]] == 1 )
            {
                if( mp2.find( v1[i] ) == mp2.end() )
                {
                    ans.push_back( v1[i] );
                }
            }
        }

        return ans;

    }
};
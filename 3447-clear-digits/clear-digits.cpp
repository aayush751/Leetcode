class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] >= 97 and s[i] <= 122 )
            {
                st.push( s[i] );
            }
            else
            {
                if( !st.empty() )
                {
                    st.pop();
                }
            }
        }

        string ans = "";

        while( !st.empty() )
        {
            ans.push_back( st.top() );
            st.pop();
        }
        
        reverse( ans.begin(), ans.end() );

        return ans;
    }
};
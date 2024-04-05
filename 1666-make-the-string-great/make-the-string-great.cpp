class Solution {
public:
    string makeGood(string s) {
        stack< char > st;

        for(int i = 0; i < s.size(); i++ )
        {
            if( st.empty() )
            {
                st.push( s[i] );
            }
            else if( s[i] == st.top() or s[i] != st.top() )
            {
                if( s[i] + 32 == st.top() or s[i] - 32 == st.top() )
                {
                    st.pop();
                }
                else
                {
                    st.push( s[i] );
                }
            }
        }

        s = "";
        while( !st.empty() )
        {
            char x = st.top();
            st.pop();
            s = s + x;
        }

        reverse( begin(s), end(s) );

        return s;
    }
};
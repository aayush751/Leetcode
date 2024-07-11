class Solution {
public:
    string reverseParentheses(string s) {
        // sbse phle stack se bna rhe hain ye quesiton ko
        stack<char> st;

        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == ')' )
            {
                string temp = "";

                while( st.top() != '(' )
                {
                    temp += st.top();
                    st.pop();
                }
                st.pop();

                for( char ch: temp )
                {
                    st.push(ch);
                }
            }
            else
            {
                st.push( s[i] );
            }
        }

        string ans = "";

        while( !st.empty() )
        {
            ans += st.top();
            st.pop();
        }

        reverse( begin(ans), end(ans) );
        return ans;
    }
};
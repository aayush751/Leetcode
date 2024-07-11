class Solution {
public:
    string reverseParentheses(string s) {
        // now using wormhole technique
        int n = s.size();
        vector<int> oppoIndex(n,-1);
        stack<int> st;

        for(int i = 0; i < n; i++ )
        {
            if( s[i] == '(' )
            {
                st.push( i );
            }
            else if( s[i] == ')' )
            {
                int openIndex = st.top();
                st.pop();
                oppoIndex[openIndex] = i;
                oppoIndex[i] = openIndex;
            }
        }

        string ans = "";
        int dir = 1;
        for(int i = 0; i < n; i += dir )
        {
            if( s[i] == '(' or s[i] == ')' )
            {
                i = oppoIndex[i];
                dir = dir * -1;
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};
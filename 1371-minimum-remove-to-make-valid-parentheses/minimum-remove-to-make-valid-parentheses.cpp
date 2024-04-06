class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // PHLE STACK se ban rhe hain


        // stack< int > st;

        // for(int i = 0; i < s.size(); i++ )
        // {
        //     if( s[i] == '(' )
        //     {
        //         st.push( i );
        //     }
        //     else if( s[i] == ')' )
        //     {
        //         if( st.empty() )
        //         {
        //             s[i] = '$';
        //         }
        //         else
        //         {
        //             st.pop();
        //         }
        //     }
        // }

        // while( !st.empty() )
        // {
        //     s[st.top()] = '$';
        //     st.pop();
        // }

        // string ans = "";

        // for(int i = 0; i < s.size(); i++ )
        // {
        //     if( s[i] != '$' )
        //     {
        //         ans += s[i];
        //     }
        // }
        

        // ab bina stack lekr solve kr rhe hain

        int cnt = 0;

        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '(' )
            {
                cnt++;
            }
            else if( s[i] == ')' )
            {
                if( cnt == 0 )
                {
                    s[i] = '$';                 
                }
                else
                {
                    cnt--;
                }
            }
        }

        cnt = 0;

        for(int i = s.size() - 1; i > -1; i-- )
        {
            if( s[i] == ')' )
            {
                cnt++;
            }
            else if( s[i] == '(' )
            {
                if( cnt == 0 )
                {
                    s[i] = '$';
                }
                else
                {
                    cnt--;
                }
            }
        }


        string ans = "";

        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] != '$' )
            {
                ans += s[i];
            }
        }

        return ans;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        // esme dip dekhna hai....
        //  jse ki  current element se bada agar koe aata hai toh stack me push kro...agr chhota aata hai toh remove kr stack k top element ko and chhota value ko insert kro stack me. 

        stack< char > st;

        for(int i = 0; i < num.size(); i++ )
        {
            while( k > 0 and !st.empty() and st.top() > num[i] )
            {
                k--;
                st.pop();
            }

            if( !st.empty() or num[i] != '0' )
            {
                st.push( num[i] );
            }
        }

        while( k > 0 and !st.empty() )
        {
            k--;
            st.pop();
        }


        if( st.empty() )
        {
            return "0";
        }

        string ans;
        
        while( !st.empty() )
        {
            ans += st.top();
            st.pop();
        }

        reverse( begin(ans), end(ans) );

        return ans;
    }
};
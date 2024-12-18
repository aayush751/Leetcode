class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // ye next greater element jsa question hai
        int n = prices.size();

        vector< int > result(n);
        stack< int > st;

        for( int i = 0; i < n; i++ )
        {
            while( !st.empty() and prices[i] <= prices[st.top()] )
            {
                int j = st.top();
                st.pop();
                result[j] = prices[j] - prices[i];
            }
            st.push( i );
        }                

        while( !st.empty() )
        {
            int top = st.top();
            st.pop();

            result[top] = prices[top];
        }                             

        return result;       
    }
};
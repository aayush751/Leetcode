class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack< pair< int, int > > st;

        int n = temp.size();

        vector<int> ans(n, 0);

        for(int i = n - 1; i > -1; i-- )
        {
            while( st.size() and st.top().first <= temp [i] )
            {
                st.pop();
            }

            if( st.size() and st.top().first > temp[i] )
            {
                ans[i] = st.top().second - i;
            }

            st.push({temp[i], i});
        }

        return ans;
    }
};
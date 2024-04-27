class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int cnt = 0;
        int maxi = 0;
        unordered_set< int > st;

        for(auto i: nums )
        {
            st.insert( i );
        }

        for(auto it = st.begin(); it != st.end(); it++ )
        {
            int check = *it - 1;
            if( st.find( check ) == st.end() )
            {
                cnt = 1;
                int value = *it + 1;

                while( st.find(value) != st.end() )
                {
                    cnt++;
                    value++;
                }
            }
            else
            {
                continue;
            }

            maxi = max( maxi, cnt );
        }


        return maxi;
    }
};
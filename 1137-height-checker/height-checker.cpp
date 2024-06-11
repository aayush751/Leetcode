class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // without using sorting function. 
        // we will use counting sort


        vector< int > count(101,0);

        for( auto h: heights )
        {
            count[h]++;
        }

        int ans = 0, id = 1;

        for(int i = 0; i < heights.size(); i++ )
        {
            while( count[id] == 0 )
            {
                id++;
            }

            if( heights[i] == id )
            {
                count[id]--;
            }
            else
            {
                ans++;
                count[id]--;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {

        int total_rectangle = 0;

        sort( begin(p), end(p) );


        int n = p.size();
        for(int i = 0; i < p.size(); )
        {
            total_rectangle++;
            int maxi = p[i][0] + w;

            while( i < n and p[i][0] <= maxi )
            {
                i++;
            }
        }
        return total_rectangle;

    }
};
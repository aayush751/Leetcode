class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& g, int m ) {
        int windowSum = 0, zeroSum = 0, maxWindowSum = 0, n = g.size();

        for(int i = 0; i < n; i++ )
        {
            if( g[i] == 0 )
            {
                zeroSum += customers[i];
            }

            if( i < m )
            {
                windowSum += ( g[i] == 1 ? customers[i] : 0 );
            }
            else
            {
                windowSum += ( g[i] == 1 ? customers[i] : 0 ) - ( g[i - m] == 1 ? customers[i - m] : 0 );
            }

            maxWindowSum = max( maxWindowSum, windowSum );
        }

        return maxWindowSum + zeroSum;
    }
};
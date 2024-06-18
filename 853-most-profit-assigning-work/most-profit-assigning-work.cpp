class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w ) {
        int n = d.size();
        int m = w.size();

        vector< pair< int, int > > jobs(n);

        for(int i = 0; i < n; i++ )
        {
            jobs[i] = { d[i], p[i] };
        }


        sort( jobs.begin(), jobs.end() );
        sort( w.begin(), w.end() );

        int profSum = 0, maxProfit = 0, j = 0;

        for(int i = 0; i < m; i++ )
        {
            while( j < m and jobs[j].first <= w[i] )
            {
                maxProfit = max( maxProfit, jobs[j].second );
                j++;
            }

            profSum += maxProfit;
        }

        return profSum;
    }
};
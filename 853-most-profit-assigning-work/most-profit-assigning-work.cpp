class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = d.size();
        int m = w.size();
        int maxEl = *max_element( d.begin(), d.end() );

        vector< int > prof( maxEl + 1, 0 );

        for(int i = 0; i < n; i++ )
        {
            prof[d[i]] = max( prof[d[i]], p[i] );
        }

        for(int i = 1; i < prof.size(); i++ )
        {
            prof[i] = max( prof[i], prof[i - 1] );
        }

        int profSum = 0;

        for(int i = 0; i < m; i++ )
        {
            if( w[i] <= maxEl )
            {
                profSum += prof[w[i]];
            }
            else
            {
                profSum += prof[maxEl];
            }
        }

        return profSum;
    }
};
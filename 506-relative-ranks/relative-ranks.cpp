class Solution {
public:


    bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector< pair< int, int > > pv;
        vector< string > ans(n);
        for(int i = 0; i  < score.size(); i++ )
        {
            pv.push_back( make_pair(score[i], i) );
        }

        sort( begin(pv), end(pv) );

        int rank = 0;
        for(int i = pv.size() - 1; i > -1; i-- )
        {
            rank++;

            if( rank == 1 )
            {
                ans[pv[i].second] = "Gold Medal";
            }
            else if( rank == 2 )
            {
                ans[pv[i].second] = "Silver Medal";
            }
            else if( rank == 3 )
            {
                ans[pv[i].second] = "Bronze Medal";
            }
            else
            {
                ans[pv[i].second] = to_string( rank );
            }
        }

        return ans;
    }
};
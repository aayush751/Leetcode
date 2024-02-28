class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int size = score.size();

        vector< string > ans( size );

        priority_queue< int > pq;

        for(auto i: score )
        {
            pq.push(i);
        }

        unordered_map< int, int > mp;

        for(int i = 0; i < score.size(); i++ )
        {
            mp[score[i]] = i;
        }

        int k = 3;
        int rank = 4;
        while( !pq.empty() )
        {
            int top = pq.top();
            pq.pop();

            if( k == 3 )
            {
                ans[mp[top]] = "Gold Medal";
                k--;
            }
            else if( k == 2 )
            {
                ans[mp[top]] = "Silver Medal";
                k--;
            }
            else if( k == 1 )
            {
                ans[mp[top]] = "Bronze Medal";
                k--;
            }
            else
            {
                string temp = to_string(rank);
                ans[mp[top]] = temp;
                rank++;
            }

        }

        return ans;
        
    }
};
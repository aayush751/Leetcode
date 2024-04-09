class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map< int, int > mp;
        // pair< int
        priority_queue< pair< int, int > > pq;

        for(auto i: arr )
        {
            mp[i]++;
        }

        int n = arr.size() / 2;

        for( auto i: mp )
        {
            pq.push(make_pair( i.second, i.first) );
        }

        int cnt = 0;
        int size = arr.size();
        while( !pq.empty() )
        {
            int ele = pq.top().first;
            pq.pop();
            int freq = ele;

            cnt++;
            size = size - freq;

            if( size <= n )
            {
                return cnt;
            }
        }

        return cnt;
    }
};
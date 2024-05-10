class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue< pair< double, pair< int , int > > > pq;

        // for(int i = 0; i < arr.size() - 1; i++ )
        // {
        //     for(int j = i + 1; j < arr.size(); j++ )
        //     { 
        //         pq.push( arr[i]/arr[j] ).make_pair( arr[i], arr[j] );
        //     }
        // }
        int n = arr.size();

        for(int i = 0; i < n; i++ )
        {
            for(int j = i + 1; j < n; j++ )
            {
                double val = ( arr[i] * 1.0 ) / arr[j];
                pq.push({val, {i,j}});

                if ( pq.size() > k )
                {
                    pq.pop();
                }
            }
        }

        pair< int , int > id = pq.top().second;
        return { arr[id.first], arr[id.second] };
    }
};
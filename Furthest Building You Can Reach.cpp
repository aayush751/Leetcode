class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {

        int n = h.size();
        int low = 0;
        int high = n;

        auto check = [&]( int p ) -> bool 
        {
            int rem_brick = b;
            vector< int > need;


            for(int i = 0; i < p; i++ )
            {
                if( h[i + 1] > h[i] )
                {
                    need.push_back( h[i + 1] - h[i] );
                }
            }

            sort( need.begin(), need.end() , [](int a, int b) {
                return a > b;
            });

            while( need.size() and rem_brick >= need.back() )
            {
                rem_brick -= need.back();
                need.pop_back();
            }

            return l >= need.size();
        };


        while( low < high - 1 )
        {
            int mid = low + ( high - low ) / 2;

            if( check( mid ) )
            {
                low = mid;
            }
            else
            {
                high =  mid;
            }
        }

        return low;
    }
};

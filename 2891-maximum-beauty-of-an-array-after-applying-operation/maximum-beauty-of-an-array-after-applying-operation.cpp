class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector< pair< int, int > > vp(n);

        for(int i = 0; i < n; i++ )
        {
            vp[i] = { nums[i] - k, nums[i] + k };
        }

        sort( begin(vp), end(vp) );

        deque< int > deq;
        int maxBeauty = 0;

        for( pair< int, int >& interval: vp )
        {
            while( !deq.empty() and deq.front() < interval.first )
            {
                deq.pop_front();
            }

            deq.push_back( interval.second );

            maxBeauty = max( maxBeauty, (int)deq.size() );
        }

        return maxBeauty;


    }
};
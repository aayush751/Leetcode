class Solution {
public:
    #define P pair< int, int >
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();

        vector< P > vp(n);

        for(int i = 0; i < n; i++ )
        {
            vp[i] = { nums[i], i };
        }

        make_heap( begin(vp), end(vp), greater<>() );

        while( k-- )
        {
            pop_heap( begin(vp), end(vp), greater<>() ); //ye kia ki min element ko last me put kr dia pq k
            pair< int, int > temp = vp.back();
            vp.pop_back();

            int number = temp.first;
            int idx = temp.second;

            nums[idx] = nums[idx] * multiplier;
            vp.push_back( { nums[idx], idx } );
            push_heap( begin(vp), end(vp), greater<>() );
        }

        return nums;
    }
};
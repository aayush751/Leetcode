class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long txor = 0;

        for( auto ele: nums )
        {
            txor ^= ele;
        }

        long long
         mask = ( txor & (txor - 1 ) ) ^ txor;
        vector< int > res(2);

        for(auto ele: nums )
        {
            if( ( ele & mask ) == 0 )
            {
                res[0] = res[0] ^ ele;
            }
            else
            {
                res[1] = res[1] ^ ele;
            }
        }

        return res;
    }
};
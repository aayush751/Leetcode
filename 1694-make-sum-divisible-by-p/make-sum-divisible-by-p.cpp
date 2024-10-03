class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalSum = 0;

        for(int& num: nums )
        {
            totalSum += num;
        }

        int targetMod = totalSum % p;
        if( targetMod == 0 ) return 0;

        unordered_map< int, int > prefix_map;

        prefix_map[0] = -1;

        long prefixSum = 0;
        int minLength = n;

        for( int i = 0; i < n; i++ )
        {
            prefixSum += nums[i];

            int currentMod = prefixSum % p;

            int requiredMod = ( currentMod - targetMod + p ) % p;

            if( prefix_map.find( requiredMod ) != prefix_map.end() )
            {
                minLength = min( minLength, i - prefix_map[requiredMod] );
            }

            prefix_map[currentMod] = i; 
        }

        return minLength == n ? -1 : minLength;
    }
};
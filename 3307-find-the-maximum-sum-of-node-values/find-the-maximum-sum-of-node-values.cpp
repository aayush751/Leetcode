class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, bb = INT_MAX;

        for(auto el: nums )
        {
            if( (el ^ k ) > el )
            {
                sum += el ^ k;
                bb = min( bb, (long long)(el ^ k) - el );
                cnt++;
            }
            else
            {
                sum += el;
                bb = min( bb, (long long)el - ( el ^ k) );
            }
        }

        if( cnt % 2 == 0 )
        {
            return sum;
        }
        return sum - bb;
    }
};
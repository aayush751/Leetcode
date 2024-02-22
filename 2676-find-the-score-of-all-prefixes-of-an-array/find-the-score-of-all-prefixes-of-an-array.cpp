class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {

        int size = nums.size();
        vector< long long > score;

        long long max = INT_MIN;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] > max )
            {
                max = nums[i];
            }

            if( i != 0 )
            {
                sum = score.back();
            }

            score.push_back( sum + nums[i] + max );
        }

        return score;
    }
};
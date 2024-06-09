class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size(), prefSum = 0;
        unordered_map< int, int > prevOcc;
        prevOcc[0] = 1;

        int ans = 0;

        for(int i = 0; i < n; i++ )
        {
            prefSum = (prefSum + nums[i] % k + k) % k;

            ans += prevOcc[prefSum];
            prevOcc[prefSum]++;
        }

        return ans;
    }
};
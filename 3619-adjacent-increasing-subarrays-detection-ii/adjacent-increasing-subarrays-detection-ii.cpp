class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

        // Calculate lengths of increasing subarrays ending at each index
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) left[i] = left[i-1] + 1;
        }

        // Calculate lengths of increasing subarrays starting at each index
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) right[i] = right[i+1] + 1;
        }

        int maxK = 0;
        // Find maximum k where two adjacent increasing subarrays exist
        for (int i = 0; i < n - 1; i++) {
            int k = min(left[i], right[i+1]);
            maxK = max(maxK, k);
        }

        return maxK;
    }
};
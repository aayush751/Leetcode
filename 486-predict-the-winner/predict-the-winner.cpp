class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // Optimization: Player 1 can always force a win/tie if length is even
        if (n % 2 == 0) return true;

        // dp[i] stores the max net score difference for subarray starting at index i
        std::vector<int> dp = nums;

        // Build DP from subproblems of length 2 up to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i] = std::max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

        // Player 1 wins if net score difference for full array nums[0...n-1] >= 0
        return dp[0] >= 0;
    }
};
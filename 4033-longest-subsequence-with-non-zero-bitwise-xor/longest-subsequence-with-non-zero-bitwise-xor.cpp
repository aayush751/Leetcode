class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool hasNonZero = false;

        for (int val : nums) {
            totalXor ^= val;
            if (val != 0) {
                hasNonZero = true;
            }
        }

        // Case 1: Overall XOR is non-zero
        if (totalXor != 0) {
            return n;
        }

        // Case 2: Overall XOR is zero, but at least one non-zero element exists
        if (hasNonZero) {
            return n - 1;
        }

        // Case 3: All elements are zero
        return 0;
    }
};
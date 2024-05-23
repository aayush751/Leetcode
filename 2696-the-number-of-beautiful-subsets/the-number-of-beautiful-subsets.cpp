class Solution {

    private:
    void backtrack(vector<int>& nums, int k, int start, unordered_map<int, int>& freq, int& count) {
        for (int i = start; i < nums.size(); ++i) {
            int num = nums[i];
            // Check if adding nums[i] to the subset violates the condition
            if (freq[num - k] > 0 || freq[num + k] > 0) {
                continue;
            }
            // Include nums[i] in the subset
            freq[num]++;
            count++;
            backtrack(nums, k, i + 1, freq, count);
            // Exclude nums[i] from the subset
            freq[num]--;
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;
        backtrack(nums, k, 0, freq, count);
        return count;
    }
};
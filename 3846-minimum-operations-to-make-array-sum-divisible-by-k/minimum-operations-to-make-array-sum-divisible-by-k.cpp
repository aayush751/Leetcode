class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long S = 0;
    for (int x : nums) S += x;

    int rem = S % k;
    return rem == 0 ? 0 : rem;
    }
};
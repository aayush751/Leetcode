class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
    int num = 0;
    for (int bit : nums) {
        num = ((num << 1) | bit) % 5; // Shift left and add bit, keep mod 5
        answer.push_back(num == 0);
    }
    return answer;
    }
}; 
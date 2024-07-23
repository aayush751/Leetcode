class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
    
    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Custom comparator for sorting
    auto comparator = [&freqMap](int a, int b) {
        if (freqMap[a] == freqMap[b]) {
            return a > b; // If frequencies are the same, sort by value in descending order
        }
        return freqMap[a] < freqMap[b]; // Otherwise, sort by frequency in ascending order
    };

    // Sort the array using the custom comparator
    sort(nums.begin(), nums.end(), comparator);

    return nums;
    }
};
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;
        sort(begin(nums), end(nums));
        int maxStreak = 0;
        for(int &num : nums) { //2, 4 
            //check if this number is a perfect square
            int root = (int)sqrt(num);
            if(root*root == num && mp.find(root) != mp.end()) {
                mp[num] = mp[root] + 1;
            } else {
                mp[num] = 1;
            }
            maxStreak = max(maxStreak, mp[num]);
        }
        return maxStreak < 2 ? -1 : maxStreak;
    }
};
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                v.push_back(nums[i]);
            }
        }
        for(int i=1; i<v.size()-1; i++)
        {
            if((v[i] > v[i-1] and v[i] > v[i+1]) or (v[i] < v[i-1] and v[i] < v[i+1]))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
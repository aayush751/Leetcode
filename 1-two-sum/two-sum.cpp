class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > v;
        for(int i=0; i<nums.size(); i++)
        {
            v.push_back(make_pair(nums[i], i));
        }
        sort(begin(v), end(v));
        int k = 0;
        int j = v.size() - 1;
        while(k<j)
        {
            if( v[k].first + v[j].first == target)
            {
                return {v[k].second , v[j].second};
            }
            else if(v[k].first + v[j].first > target)
            {
                j--;
            }
            else
            {
                k++;
            }
        }
        return {};
    }
};
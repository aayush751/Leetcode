class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> ans;

        for(auto i: nums)
        {
            ans.insert(i);
        }

        for(int i = 0; i <= nums.size(); i++ )
        {
            if( ans.find(i) == ans.end() )
            {
                return i;
            }
        }

        return 0;
    }
};

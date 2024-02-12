class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;

        int majo = INT_MIN;

        for(int i = 0; i < nums.size(); i++ )
        {
           if( cnt == 0 )
           {
               cnt = 1;
               majo = nums[i];
           }
           else if( nums[i] == majo )
           {
               cnt++;
           }
           else
           {
               cnt--;
           }
        }

        return majo;
    }
};
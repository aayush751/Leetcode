class Solution {
public:
    int specialArray(vector<int>& nums) {
        int cnt = 0;


        sort( nums.rbegin(), nums.rend() );

        for(int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] >= cnt )
            {
                cnt++;
                if( cnt > nums[i] )
                {
                    return -1;
                }
            }
            else
            {
                return cnt;
            }
        }

        return nums.size();
    }
};
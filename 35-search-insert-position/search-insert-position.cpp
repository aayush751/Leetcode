class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();

        int low = 0;
        int high = nums.size() - 1;

        int mid = ( high + low )/2;

        while( low <= high )
        {
            if( nums[mid] >= target )
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }

            mid = ( high + low )/2;
        }
        return ans;
    }
};
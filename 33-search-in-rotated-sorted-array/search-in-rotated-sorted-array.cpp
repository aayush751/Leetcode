class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        int mid = low + ( high - low ) / 2;
        while( low <= high )
        {

            if( nums[mid] == target )
            {
                return mid;
            }
            // agar left part sorted hai toh
            if( nums[low] <= nums[mid] )
            {
                if( nums[low] <= target and target <= nums[mid] )
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else //agr right part sorted hai toh
            {
                if( nums[mid] <= target and target <= nums[high] )
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            mid = low + ( high - low ) / 2;
        }

        return -1;
    }
};
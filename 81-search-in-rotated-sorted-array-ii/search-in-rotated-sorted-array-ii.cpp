class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        int mid = low + ( high - low ) / 2;

        while( low <= high )
        {

            if ( nums[mid] == target )
            {
                return true;
            }


            // edge case
            if( nums[low] == nums[mid] and nums[mid] == nums[high] )
            {
                low = low + 1;
                high = high - 1;
                continue;
            }

            
            // agr left part sort hai toh

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
            else
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

        return false;
    }
};
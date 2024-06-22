class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int oddCount = 0;
        
        int oddSubArray = 0;

        int left = 0;

        int sum = 0;
        for(int right = 0; right < nums.size(); right++ )
        {
            if( nums[right] % 2 == 1 )
            {
                oddCount++;
                oddSubArray = 0;
            }

            while( oddCount == k )
            {
                oddSubArray++;
                oddCount = oddCount - ( nums[left] % 2 == 1 );
                left++;
            }

            sum = sum + oddSubArray;
        }

        return sum;
    }
};
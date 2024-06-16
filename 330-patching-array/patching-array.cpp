class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // ye question me ye bola hai ki given array me jitna baar value add kre taki jo array element ko sum krk n k equal aa jaye...


        // phle case me [1,3] hai and n = 6;
        // ek variable rhega jo bataega ki maxSumValue kitna bnega array element se
        // and ek counter for count of patch we'll do.
        // phle value hai 1..Ab tk hmara maxSumValue 1 ko add krk sirf 1 hi bn skta hai toh 1 ko simple add kr dengein maxValuSum wale variable me...Phir next value array me 2 chiye taki 2 se mera sum 1,2,3 bn sake

        long int maxValueSum = 0;
        long int patches_required = 0;

        int size = nums.size();

        int i = 0;

        while( maxValueSum < n )
        {
            if( i < size and maxValueSum + 1 >= nums[i] )
            {
                maxValueSum = maxValueSum + nums[i];
                i++;
            }
            else
            {
                patches_required++;
                maxValueSum += ( maxValueSum + 1 );
            }
        }

        return patches_required;

    }
};
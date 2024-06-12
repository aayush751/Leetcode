class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = nums.size() - 1;
        int i = 0, mid = 0;

        while( mid <= j )
        {
            switch( nums[mid] ){
                case 0: swap( nums[mid], nums[i] );
                i++;
                mid++;
                break;

                case 1: mid++;
                break;

                case 2: swap( nums[mid], nums[j] );
                j--;
                break;
            }
        }
    }
};
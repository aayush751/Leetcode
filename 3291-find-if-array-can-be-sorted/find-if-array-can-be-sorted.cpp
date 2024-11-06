class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector< int > setBitArray;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++ )
        {
            int num = nums[i];
            int count = 0;
            while( num > 0 )
            {
                if( num & 1 == 1 )
                {
                    count++;
                }
                num = num >> 1;
            }
            setBitArray.push_back( count );
        }

        for(int i = 0; i < nums.size(); i++ )
        {
            for(int j = 0; j < n - i - 1; j++ )
            {
                if( nums[j] > nums[j + 1] and setBitArray[j] == setBitArray[j + 1] )
                {
                    swap( nums[j], nums[j + 1] );
                    swap( setBitArray[j], setBitArray[j + 1] );
                }
            }
        }

        bool flag = false;

        for(int i = 0; i < n - 1; i++ )
        {
            if( nums[i] > nums[i + 1] )
            {
                return false;
            }
        }

        return true;
    }
};
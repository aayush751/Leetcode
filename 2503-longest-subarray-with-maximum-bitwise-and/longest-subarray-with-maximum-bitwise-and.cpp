class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int k = 0;

        for(auto i: nums )
        {
            k = max( k, i );
        }

        int length = 0;
        int maxLength = 0;
        for(auto i: nums )
        {
            if( i == k )
            {
                length++;
            }
            else
            {
                maxLength = max( maxLength, length );
                length = 0;
            }
        }

        maxLength = max( maxLength, length );

        return maxLength;
    }
};
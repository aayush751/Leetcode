class Solution {
public:
    int mySqrt(int c) {
        int low = 0, high = c;
        long long mid = low + ( high - low ) / 2;

        int ans = -1;

        while( low <= high )
        {
            if( mid * mid <= c )
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            mid = low + ( high - low ) / 2;
        }

        return ans;
    }
};
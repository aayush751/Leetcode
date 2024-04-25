class Solution {
public:
    int getSqrt( int c )
    {
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
    bool judgeSquareSum(int c) {
        long long i = 0, j = getSqrt(c);

        while( i <= j )
        {
            long long sum = i * i + j * j;

            if( sum == c )
            {
                return 1;
            }
            else if( sum < c )
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return 0;
    }
};
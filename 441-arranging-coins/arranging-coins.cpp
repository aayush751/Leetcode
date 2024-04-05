class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1, right = n;

        long long mid = left + ( right - left ) / 2;
        int ans = 0;
        while( left <= right )
        {
            if( mid * ( mid + 1 ) / 2 <= n )
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

            mid = left + ( right - left ) / 2;
        }

        return ans;
    }
};
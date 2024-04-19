class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num;
        long long mid = low + ( high - low ) / 2;

        
        while( low <= high )
        {
            if( mid * mid == num )
            {
                return true;
            }
            else if( mid * mid > num )
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + ( high - low ) / 2;
        } 

        return false;
    }
};
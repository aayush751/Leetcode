class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0, j = sqrt(c);

        while( i <= j )
        {
            long long  sum = i * i + j * j;
            if( sum == c )
            {
                return true;
            }
            else if( sum > c )
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
    }
};
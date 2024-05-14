class Solution {
public:
    int numSquares(int n) {
        // ek theorem se ye derive hua hai solution

        int square_val = sqrt(n);

        if( square_val * square_val == n )
        {
            return 1;
        }

        while( n % 4 == 0 )
        {
            n = n / 4;
        }

        if( n % 8 == 7 )
        {
            return 4;
        }

        for(int i = 1; i * i <= n; i++ )
        {
            int element_A = i * i;
            int element_B = sqrt( n - element_A );

            if( element_B * element_B == n - element_A )
            {
                return 2;
            }
        }
        
        return 3;
    }
};
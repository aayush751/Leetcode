class Solution {
public:
    int tribonacci(int n) {
        if( n == 0 )
        {
            return 0;
        }

        if(  n == 1 or n == 2 )
        {
            return 1;
        }

        int next = 0, first = 0, second = 1, third = 1;

        n = n - 2;

        while( n-- )
        {
            next = first + second + third;
            first = second;
            second = third;
            third = next;
        }

        return next;
    }
};
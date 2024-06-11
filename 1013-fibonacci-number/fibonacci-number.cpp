class Solution {
public:

    int fibo(int n, vector< int > &memo )
    {
        // base case
        if( n <= 1 )
        {
            return n;
        }

        memo[n] = fibo(n - 1, memo ) + fibo( n - 2, memo );

        return memo[n];
    }
    int fib(int n) {
        // sbse phle recursion and memoisation
        vector< int > ans( n + 1 );
        return fibo(n, ans );
    }
};
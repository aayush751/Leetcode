class Solution {
public:
    // bool solve( int n )
    // {
    //     if (n <= 0) return false;

    //     while (n % 2 == 0) n /= 2;
    //     while (n % 3 == 0) n /= 3;
    //     while (n % 5 == 0) n /= 5;

    //     return n == 1;
    // }
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int next_2 = 2, next_3 = 3, next_5 = 5;

        for (int i = 1; i < n; i++) {
            int next_ugly = min( {next_2, next_3, next_5} );

            ugly[i] = next_ugly;

            if (next_ugly == next_2) next_2 = ugly[++i2] * 2;
            if (next_ugly == next_3) next_3 = ugly[++i3] * 3;
            if (next_ugly == next_5) next_5 = ugly[++i5] * 5;
        }

        return ugly[n - 1];
    }
};
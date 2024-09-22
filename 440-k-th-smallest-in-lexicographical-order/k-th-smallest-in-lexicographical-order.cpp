class Solution {
public:

    int countSteps( int n, long long prefix, long long nextPrefix ) 
    {
        int steps = 0;
        while ( prefix <= n ) 
        {
            steps += min((long long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) 
    {
        long long current = 1;
        k--;
        
        while (k > 0) 
        {
            int steps = countSteps(n, current, current + 1);
            if (steps <= k) 
            {
                current++;
                k -= steps;
            } 
            else
            {
                current *= 10;
                k--;
            }
        }
        return current;
    }
};
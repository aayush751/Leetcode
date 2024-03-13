class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n), suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = n;
        int sum_p = 1;
        int sum_s = n;

        for(int i = 2; i <= n; i++ )
        {
            sum_p += i;
            prefix[i-1] = sum_p;
        }

        for(int i = n - 1; i > 0; i-- )
        {
            sum_s += i;
            suffix[i - 1] = sum_s;
        }

        int ans = -1;

        for(int i = 0; i < prefix.size(); i++ )
        {
            if( prefix[i] == suffix[i] )
            {
                return i + 1;
            }
        }

        return ans;
    }
};
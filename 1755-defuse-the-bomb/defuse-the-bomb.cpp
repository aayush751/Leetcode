class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector< int > result( n, 0 );

        if( k == 0 ) return result;

        int i, j;

        if( k > 0 )
        {
            i = 1;
            j = k;
        }
        else
        {
            i = n - abs(k);
            j = n - 1;
        }

        int Sum = 0;
        
        for(int itr = i; itr <= j; itr++ )
        {
            Sum += code[itr];
        }

        for(int idx = 0; idx < n; idx++ )
        {
            result[idx] = Sum;

            Sum -= code[i % n];
            i++;

            Sum += code[( j + 1 ) % n];
            j++;
        }

        return result;
    }
};
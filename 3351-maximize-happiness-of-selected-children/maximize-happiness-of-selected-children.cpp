class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort( begin(h), end(h) );
        int n = h.size();


        long long values = 0;
        long long dec = 0;
        for(int i = n - 1; i > -1; i-- )
        {
            if( k > 0 )
            {
                values += ( h[i] - dec > 0 ) ? h[i] - dec : 0;
                k--;
                dec++;
            }
            else
            {
                break;
            }
        }

        return values;
    }
};
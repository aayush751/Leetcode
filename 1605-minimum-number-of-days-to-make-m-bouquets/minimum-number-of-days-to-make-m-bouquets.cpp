class Solution {
public:

    bool solve( int mid, vector< int >& b, int m, int k )
    {
        int conseCount = 0;
        int noOfBouquets = 0;

        for(int i = 0; i < b.size(); i++ )
        {
            if( b[i] <= mid )
            {
                conseCount++;
            }
            else
            {
                conseCount = 0;
            }

            if( conseCount == k )
            {
                noOfBouquets++;
                conseCount = 0;
            }
        }

        return noOfBouquets >= m;
    }
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();

        if( (long)m * k > n )
        {
            return -1;
        }

        int low = 1, high = *max_element( b.begin(), b.end() );
        int ans = -1;

        while( low <= high )
        {
            int mid = low + ( high - low ) / 2;

            if( solve(mid, b, m, k) )
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + ( high - low ) / 2;
        }

        return ans;
    }
};
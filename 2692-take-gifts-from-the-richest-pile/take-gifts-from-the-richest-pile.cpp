class Solution {
public:
    #define ll long long
    long long sqrts( long long num )
    {
        long long l = 0, r = num;
        ll ans = -1;

        while( l <= r )
        {
            ll mid = l + ( r - l ) / 2;

            if( mid * mid <= num )
            {
                return mid;
            }
            else if( mid * mid < num )
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue< ll > pq;

        for( int& gift: gifts )
        {
            pq.push( gift );
        }

        while( k-- )
        {
            ll top = pq.top();
            pq.pop();
            pq.push( sqrt(top) );
        }

        ll sum = 0;

        while( !pq.empty() )
        {
            ll top = pq.top();
            pq.pop();

            sum += top;
        }

        return sum;
    }
};
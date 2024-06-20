class Solution {
public:

    bool solve( int mid, vector<int>& p, int m )
    {
        int countOfBallsPlaced = 1, prevId = 0;

        for(int i = 1; i < p.size(); i++ )
        {
            if( p[i] - p[prevId] >= mid )
            {
                countOfBallsPlaced++;
                prevId = i;
            }
        }

        return ( countOfBallsPlaced >= m );
    }
    int maxDistance(vector<int>& p, int m) {
        
        sort( p.begin(), p.end() );
        int l = 0, r = *max_element( p.begin(), p.end() ), ans = -1;

        while( l <= r )
        {
            int mid = ( l + r ) / 2;

            if( solve( mid, p, m) )
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
};
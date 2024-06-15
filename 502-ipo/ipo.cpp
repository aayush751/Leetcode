class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // es question me bahut kch dia hua hai...jse ki initial capital and total no of projects to pick. And captital array and profit array for each projects.


        // capital array ko sort kregein toh jitna bhi less capital wala project hai wo sara le skte hain wo bhi w initial capital se

        // iske liye vector of pair lengein usme do values jayega...ek capital array first and second is profits array

        int n = profits.size();

        vector< pair< int , int > > vp;

        for(int i = 0; i < n; i++ )
        {
            vp.push_back( make_pair( capital[i], profits[i] ) );
        }

        sort( begin(vp), end(vp) );

        priority_queue< int > pq;


        int totalProfit = w;

        int j = 0;

        for(int i = 0; i < k; i++ )
        {
            while( j < n and vp[j].first <= totalProfit )
            {
                pq.push( vp[j].second );
                j++;
            }

            if( pq.empty() )
            {
                break;
            }

            totalProfit += pq.top();
            pq.pop();
        }


        return totalProfit;
    }
};
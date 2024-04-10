class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort( begin( deck), end(deck), greater<int>() );

        deque< int > dq;

        dq.push_front( deck[0] );

        for(int i = 1; i < deck.size(); i++ )
        {
            int ele = dq.back();
            dq.pop_back();
            dq.push_front( ele );
            dq.push_front( deck[i] );
        }

        vector< int > ans;

        while( !dq.empty() )
        {
            int val = dq.front();
            dq.pop_front();
            ans.push_back( val );
        }

        return ans;
    }
};
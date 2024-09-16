class Solution {
public:
    int findMinDifference(vector<string>& tp ) {
        vector<int> minutes;

        for( string& time : tp )
        {
            int hour  = stoi( time .substr( 0, 2 ) );
            int minute  = stoi( time .substr( 3, 2 ) );
            minutes.push_back( hour * 60 + minute );
        }

        sort( begin( minutes ), end( minutes ) );

        int minDiff = 1440;

        for(int i = 1; i < minutes.size(); i++ )
        {
            int diff = minutes[i] - minutes[i - 1];
            minDiff = min( minDiff, diff );
        }

        int circularDiff = 1440 - ( minutes.back() - minutes.front() );
        minDiff = min( minDiff, circularDiff );

        return minDiff;
    }
};
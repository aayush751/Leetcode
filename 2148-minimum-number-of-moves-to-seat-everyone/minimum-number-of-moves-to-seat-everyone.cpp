class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort( begin(students), end(students) );
        sort( begin(seats), end(seats) );


        int n = seats.size();

        int ans = 0;

        for(int i = 0; i < n; i++ )
        {
            ans += abs( seats[i] - students[i] );
        }

        return ans;
    }
};
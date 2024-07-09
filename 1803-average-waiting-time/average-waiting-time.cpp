class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        long long totalWaitTime = 0;
        long long currentTime = 0;

        for(int i = 0; i < customers.size(); i++ )
        {
            long long arrivalTime = customers[i][0];
            long long serviceTime = customers[i][1];

            if( arrivalTime > currentTime )
            {
                currentTime = arrivalTime;
            }

            currentTime += serviceTime;

            totalWaitTime += currentTime - arrivalTime;
        }

        return (double)totalWaitTime/customers.size();
    }
};
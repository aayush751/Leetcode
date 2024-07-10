class Solution {
public:
    pair<int,int> maxAndIndex( vector<int>&arr )
    {
        int maxi = INT_MIN;
        int index = -1;
        for(int i = 0; i < arr.size(); i++ )
        {
            if( maxi < arr[i] )
            {
                maxi = arr[i];
                index = i;
            }
        }

        return { maxi, index };
    }
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int size = grid[0].size();
        int maxSum = 0;
        
        while( size-- )
        {
            int tempMax = 0;

            for(int i = 0; i < grid.size(); i++ )
            {
                pair< int, int > p = maxAndIndex( grid[i] );
                tempMax = max( tempMax, p.first );
                grid[i][p.second] = -1;
            }

            maxSum += tempMax;
        }

        return maxSum;
    }
};
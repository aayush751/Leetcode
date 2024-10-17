class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string( num );
        int maxNum = num;

        for(int i = 0; i < numStr.size(); i++ )
        {
            for(int j = i + 1; j < numStr.size(); j++ )
            {
                swap( numStr[i], numStr[j] );
                maxNum = max( maxNum, stoi( numStr ) );
                swap( numStr[i], numStr[j] );
            }
        }

        return maxNum;
    }
};
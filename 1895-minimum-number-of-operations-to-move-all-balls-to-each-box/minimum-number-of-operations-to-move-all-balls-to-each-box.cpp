class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector< int > oneIndex;
        vector< int > result( n, 0 );

        for(int i = 0; i < boxes.size(); i++ )
        {
            if( boxes[i] == '1' )
            {
                oneIndex.push_back( i );
            } 
        }

        for( int i = 0; i < boxes.size(); i++ )
        {
            int value = 0;
            for( auto ele: oneIndex )
            {
                value += abs( i - ele );
            }
            result[i] = value;
        }

        return result;
    }
};
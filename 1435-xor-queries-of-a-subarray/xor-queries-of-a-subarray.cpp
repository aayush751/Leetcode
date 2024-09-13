class Solution {
public:

    int xorArray( vector< int > &arr, int start, int end )
    {
        int Xor = 0;
        for(int i = start; i <= end; i++ )
        {
            Xor = Xor ^ arr[i];
        }
        return Xor;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& que) {
        
        vector< int > ans;

        for(int i = 0; i < que.size(); i++ )
        {
            int value = xorArray( arr, que[i][0], que[i][1] );
            ans.push_back( value );
        }

        return ans;

    }
};
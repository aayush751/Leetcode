class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if( arr.size() == 0 )
        {
            return {};
        }
        vector< pair< int , int > > value_idx;

        for(int i = 0; i < arr.size(); i++ )
        {
            value_idx.push_back( make_pair( arr[i], i ) );
        }


        sort( begin(value_idx), end(value_idx) );
        vector< int > result( arr.size(), 0 );
        int rank = 1;
        for(int i = 0; i < value_idx.size() - 1; i++ )
        {
            if( value_idx[i].first != value_idx[i+1].first )
            {
                result[value_idx[i].second] = rank;
                rank++;
            }
            else
            {
                result[value_idx[i].second] = rank;
            }
        }
        int size = arr.size();
        result[value_idx[size - 1].second] = rank;

        return result;
    }
};
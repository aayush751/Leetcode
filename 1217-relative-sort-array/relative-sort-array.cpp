class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map< int, int > mp;

        // yahan ordered map esliye liye taki ordering k dhyaan rakhna hai wo element ka jo sirf arr1 me hai...usko ascending order me push_back krna hai
        for(auto element: arr1 )
        {
            mp[element]++;
        }

        vector< int > ans;

        for(int i = 0; i < arr2.size(); i++ )
        {
            while( mp[arr2[i]] > 0 )
            {
                ans.push_back( arr2[i] );
                mp[arr2[i]]--;
            }
        }

        for( auto [ key, value]: mp )
        {
            while( value > 0 )
            {
                ans.push_back( key );
                value--;
            }
        }

        return ans;
    }
};
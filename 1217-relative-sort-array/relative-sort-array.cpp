class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        int maxEl = *max_element( begin(arr1), end(arr1) );

        vector< int > count(maxEl + 1, 0 );

        vector< int > ans;

        for(auto element: arr1 )
        {
            count[element]++;
        }

        for(auto ele: arr2 )
        {
            while( count[ele]-- )
            {
                ans.push_back(ele);
            }
        }

        for(int el = 0; el <= maxEl; el++ )
        {
            int freq = count[el];

            while( freq > 0 )
            {
                ans.push_back( el );
                freq--;
            }
        }
        return ans;
    }
};
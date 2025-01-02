class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int queriesLength = queries.size();
        vector< int > result( queriesLength, 0 );
        unordered_set< char > st = { 'a', 'e', 'i', 'o', 'u' };
        vector< int > prefixSum( words.size() + 1, 0 );
        int idx = 0;
        // phle preprocess kr lena hai vowel strings
        for(int i = 0; i < words.size(); i++ )
        {
            if( st.count( words[i][0] ) and st.count( words[i].back() ) )
            {
                prefixSum[i + 1] = prefixSum[i] + 1;
            }
            else
            {
                prefixSum[i + 1] = prefixSum[i];
            }
        }


        for( auto value: queries )
        {
            int start = value[0];
            int end = value[1];

            result[idx++] = prefixSum[end + 1] - prefixSum[start];
        }

        return result;
    }
};
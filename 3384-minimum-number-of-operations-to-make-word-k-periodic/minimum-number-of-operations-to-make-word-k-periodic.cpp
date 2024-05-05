class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        unordered_map< string, int > mp;

        int maxi = 0;

        for(int i = 0; i < word.size(); i+=k )
        {
            // yahan count kr rhe hain ki k length ka string kitna time appear hua hai....uske hisab se hm replace krne wale jhain
            // jiska string ka freq jada hai wahi replace krega baki sare string ko....
            string temp = word.substr(i, k );
            mp[temp]++;

            maxi = max( maxi, mp[temp] );
        }

        return word.size()/k - maxi;
    }
};
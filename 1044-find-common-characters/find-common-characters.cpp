class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector< int > minFreq(26, INT_MAX );
        vector< string > ans;
        for( string word: words )
        {//yahan hr ek words ko traverse kregein..
            vector< int > charCount(26,0);

            for( char ch: word )
            {//hr word k char ka freq find krna hai
                charCount[ ch - 'a']++;
            }

            // iske baad sbse phle wale word me jo jo char hai uska freq count krna aur jo jo nhi hai usko zero krna hai freq...taki dusre word me agr wo char aaya toh uska count zero kr dena hai.

            for(int i = 0; i < 26; i++ )
            {
                minFreq[i] = min( minFreq[i], charCount[i] );
            }
        }

        //ab jis bhi char ka freq greater than zero hoga wo answer hoga noob
        for(int i = 0; i < 26; i++ )
        {
            while( minFreq[i] > 0 )
            {
                ans.push_back( string(1, 'a' + i) );
                minFreq[i]--;
            }
        }
        return ans;
    }
};
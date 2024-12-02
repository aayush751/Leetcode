class Solution {
public:
    int isPrefixOfWord(string sentence, string sea) {
        vector<string> s;
        stringstream ss(sentence);
        string word;
        int ans = -1;
        while(ss >> word)
        {
            s.push_back(word);
        }
        int k = 0;
        for(int i=0; i<s.size(); i++)
        {
            int j = 0;
            while(j<s[i].size() and k<sea.size())
            {
                if( s[i][j] != sea[k] )
                {
                    break;
                }
                j++;
                k++;
            }
            if( k == sea.size())
            {
                ans = i+1;
                return ans;
            }
            k = 0;
        }
        return ans;

    }
};
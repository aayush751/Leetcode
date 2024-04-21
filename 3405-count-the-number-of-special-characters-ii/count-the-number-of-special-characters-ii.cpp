class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map< char, int > mp;
        vector< int > freq(26, 0);
        vector< int > up(26, -1);

        for(int i = 0; i < word.size(); i++ )
        {
            if( word[i] >= 'A' and word[i] <= 'Z' and up[word[i] - 'A'] == -1 )
            {
                freq[word[i] - 'A']++;
                up[word[i] - 'A'] = i;
            }
            
            if( word[i] >= 'a' and word[i] <= 'z' )
            {
                mp[word[i]] = i;
            }
        }

        int answer = 0;

        for(int i = 0; i < word.size(); i++ )
        {
            if( word[i] >= 'A' and word[i] <= 'Z' and freq[word[i] - 'A'] >= 1 )
            {
                char check = word[i] + 32;

                if( mp.find( check ) != mp.end() and mp[check] < up[word[i] - 'A'] )
                {
                    answer++;
                    freq[word[i] - 'A'] = 0;
                }
            }
        }

        return answer;
    }
};
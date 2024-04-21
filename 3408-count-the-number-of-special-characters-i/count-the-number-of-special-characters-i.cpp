class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set< char > st;
        vector< int > upp(26, 0);
        
        for(int i = 0; i < word.size(); i++ )
        {
            if( word[i] >= 'a' and word[i] <= 'z' )
            {
                st.insert( word[i] );
            }
            
            if( word[i] >= 'A' and word[i] <= 'Z' )
            {
                upp[word[i] - 'A']++;
            }
        } 
        
        
        int answer = 0;
        for(int i = 0; i < word.size(); i++ )
        {
            if( word[i] >= 'A' and word[i] <= 'Z' and upp[word[i] - 'A'] >= 1 )
            {
                char check = word[i] + 32;
                if( st.find( check ) != st.end() )
                {
                    answer++;
                    upp[word[i] - 'A'] = 0;
                }
            }
        }
        
        return answer;
    }
};
class Solution {
public:
    bool isValid(string word) {
        

        if( word.size() < 3 )
        {
            return false;
        }

    int vowelCount = 0;
    int consonantCount = 0;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for( char c: word )
    {
        if( isalnum(c) )
        {
            if( vowels.find(c) != vowels.end() )
            {
                vowelCount++;
            }
            else if( c >= 48 and c <= 57 )
            {
                continue;
            }
            else
            {
                consonantCount++;
            }
        }
        else
        {
            return false;
        }
    }

    return vowelCount > 0 and consonantCount > 0;

    }
};
class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        int i = 0;

        while( i < n )
        {
            char ch = word[i];
            int count = 0;

            while( i < n and ch == word[i] and count < 9 )
            {
                count++;
                i++;
            }

            comp.push_back( count + '0' );
            comp.push_back( ch );
        }

        return comp;
    }
};
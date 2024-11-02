class Solution {
public:
    bool isCircularSentence(string sentence) {
        char ch;

        for( int i = 0; i < sentence.size(); i++ )
        {
            if( sentence[i] == ' ' )
            {
                if( ch != sentence[i + 1] )
                {
                    return false;
                }
            }
            else
            {
                ch = sentence[i];
            }
        }

        if( sentence[0] != sentence[ sentence.size() - 1] )
        {
            return false;
        }

        return true;
    }
};
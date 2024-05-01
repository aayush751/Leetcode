class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";

        int found = word.find(ch);
        // ye find function hmko wo index dega jisme wo ch character present hai nhi toh -1 dega
        if( found == string::npos )
        {
            return word;
        }

        int i = 0;

        while( i < found )
        {
            char sap = word[i];
            word[i] = word[found];
            word[found] = sap;
            i++;
            found--;
        }

        return word;        
    }
};
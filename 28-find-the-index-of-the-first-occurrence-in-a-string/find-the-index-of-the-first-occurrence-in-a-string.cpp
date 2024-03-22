class Solution {
public:
    int strStr(string h, string n ) {

        int found = h.find( n );

        if( found != string:: npos )
        {
            return found;
        }

        return -1;
    }
};
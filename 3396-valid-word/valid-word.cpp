class Solution {
public:
    bool isValid(string word) {
        int n = word.size();

        if( n < 3 )
        {
            return false;
        }

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int df = false, uf = false, vf = false, cf = false, lf = false;

        for(char c: word )
        {
            if( !isdigit(c) and !isalpha(c) )
            {
                return false;
            }

            if( isdigit(c) )
            {
                df = true;
            }

            if( islower(c) )
            {
                lf = true;
            }

            if( isupper(c) )
            {
                uf = true;
            }

            if( vowels.count(c) )
            {
                vf = true;
            }
            else if( !vowels.count(c) and isalpha(c) )
            {
                cf = true;
            }
        }

        return ( df or lf or uf ) and vf and cf;
    }
};
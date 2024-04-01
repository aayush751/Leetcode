class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag = false;

        int n = s.size();
        int size = 0;
        for(int i = n - 1; i > -1; i-- )
        {
            if( s[i] != 32 )
            {
                flag = true;
                size++;
            }
            else
            {
                if( flag == true )
                {
                    return size;
                }
            }
        }

        return size;
    }
};
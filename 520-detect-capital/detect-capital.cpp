class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n = word.size();

        bool flag = false;
        int cnt = 0;
        int a = 0;
        for(int i = 0; i < word.size(); i++ )
        {
            if( i == 0 and word[i] >= 'A' and word[i] <= 'Z' )
            {
                flag = true;
                cnt++;
                a = 1;
            }
            else if( word[i] >= 'A' and word[i] <= 'Z' )
            {
                cnt++;
            }
            else
            {
                flag = false;
            }
        }

        if( flag == true and cnt == n )
        {
            return true;
        }
        else if( flag == false and cnt == 0 )
        {
            return true;
        }
        else if( cnt == 1 and ( flag == true or a == 1 ))
        {
            return true;
        }
        return false;
    }
};
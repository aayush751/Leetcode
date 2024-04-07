class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0, star_cnt = 0;

        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '(' )
            {
                cnt++;
            }
            else if( s[i] == ')' )
            {
                if( cnt == 0 )
                {
                    if( star_cnt > 0 )
                    {
                        star_cnt--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cnt--;
                }
            }
            else
            {
                star_cnt++;
            }
        }

        cnt = 0, star_cnt = 0;

        for(int i = s.size() - 1; i > -1; i-- )
        {
            if( s[i] == ')' )
            {
                cnt++;
            }
            else if( s[i] == '(' )
            {
                if( cnt == 0 )
                {
                    if( star_cnt > 0 )
                    {
                        star_cnt--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cnt--;
                }
            }
            else
            {
                star_cnt++;
            }
        }

        return true;
    }
};
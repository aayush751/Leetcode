class Solution {
public:
    bool checkRecord(string s) {

        int absent_chk = 0, late_chk = 0;

        for( char ch: s )
        {
            if( ch == 'A' )
            {
                absent_chk++;

                if( late_chk > 0 )
                {
                    late_chk = 0;
                }
            }
            else if( ch == 'L')
            {
                late_chk++;
            }
            else
            {
                if( late_chk > 0 )
                {
                    late_chk = 0;
                }
            }

            if( late_chk >= 3 or absent_chk >= 2 )
            {
                return false;
            }
        }

        return true;
    }
};
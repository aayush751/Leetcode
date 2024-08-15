class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int totalFive = 0;
        vector< int > bill( 3, 0 );

        for(auto i: bills )
        {
            if( i == 5 )
            {
                bill[0]++;
            }
            else if( i == 10 )
            {
                bill[1]++;

                if( bill[0] > 0 )
                {
                    bill[0]--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                bill[2]++;

                if( bill[1] > 0 and bill[0] > 0 )
                {
                    bill[1]--;
                    bill[0]--;
                }
                else if( bill[0] >= 3 )
                {
                    bill[0] -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    int findComplement(int num) {
        
        string bs;

        while( num > 0 )
        {
            if( ( num & 1 ) == 1 )
            {
                bs = "0" + bs;
            }   
            else
            {
                bs = "1" + bs;
            }
            
            num = num >> 1;
        }
        int ans = 0;
        int power = 0;
        for( int i = bs.size() - 1; i > -1; i-- )
        {
            ans = ans + ( bs[i] - '0' ) * pow(2, power++ );
        }

        return ans;
    }
};
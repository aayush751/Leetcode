class Solution {
public:
    int happy(int n)
    {
        int sum = 0;
        while( n > 0 )
        {
            int ld = n % 10;
            sum = sum + ld*ld;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        
        while( n > 9 )
        {
            n = happy(n);
        }
        

        if( n == 1 or n == 7 )
        return true;


        return false;
    }
};

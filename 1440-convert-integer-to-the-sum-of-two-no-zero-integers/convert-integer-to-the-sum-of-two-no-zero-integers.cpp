class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=n-1;
        int b=1;
        while(a>0)
        {
            if(a % 10 == 0)
            {
                b++;
                a=n-b;
            }
            else
            {
                a=a/10;
            }
        }
        if(b % 10 == 0)
        {
            b++;
            
        }
        if(b > 100)
        {
            b = b*10 + b;
            
        }
        a=n-b;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};
class Solution {
public:
    string countAndSay(int n) {
        string a = "1";
        int cnt = 1;
        n = n - 1;
        string res;
        while(n--)
        {
            for(int i=0; i<a.size(); i++)
            {
                if(a[i] == a[i+1])
                {
                    cnt++;
                }
                else
                {
                    res += (cnt + '0');
                    res = res + a[i];
                    cnt = 1;
                }
            }
            a = "";
            a = res;
            res = "";
        }
          return a;
    }
  

    
};
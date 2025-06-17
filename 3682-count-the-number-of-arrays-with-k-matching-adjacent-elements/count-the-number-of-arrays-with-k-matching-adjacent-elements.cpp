#define ll long long
class Solution {
public:
    int md = 1e9+7;
    int binpow(int a,int b){
        int res = 1;
        while(b){
            if(b&1){
                res = ((ll)res*a)%md;
            }
            a = ((ll)a*a)%md;
            b>>=1;
        }
        return res%md;
    }
    int mdinv(int res){
        return binpow(res,md-2);
    }
    int fact(int num){
        if(num==0 || num==1) return 1;
        int res = 1;
        for(int i=2;i<=num;i++){
            res = ((ll)res*i)%md;
        }
        return res%md;
    }
    int invfact(int num){
        int fac = fact(num);
        int invfac = mdinv(fac);
        return invfac%md;
    }
    int countGoodArrays(int n, int m, int k) {
        int nCr = ((ll)fact(n-1)* (((ll)invfact(k)*invfact(n-k-1))%md))%md;
        int power = binpow(m-1,n-k-1);
        return ((ll)nCr*(((ll)m*power)%md))%md;
    }
};
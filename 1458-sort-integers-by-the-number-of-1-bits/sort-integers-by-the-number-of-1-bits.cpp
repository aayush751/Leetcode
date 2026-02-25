class Solution {
public:
    static bool check(int a,int b){
        int setBits1 = __builtin_popcount(a);
        int setBits2 = __builtin_popcount(b);

        if(setBits1 == setBits2){
            return a<b;
        }

        return setBits1<setBits2;

    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),check);
        return arr;
    }
};
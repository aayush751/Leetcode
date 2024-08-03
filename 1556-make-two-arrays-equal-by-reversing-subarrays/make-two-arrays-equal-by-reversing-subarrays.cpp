class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& arr) {
       sort(t.begin(), t.end());
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != t[i])
                return false;
        }
        return true;
    }
};
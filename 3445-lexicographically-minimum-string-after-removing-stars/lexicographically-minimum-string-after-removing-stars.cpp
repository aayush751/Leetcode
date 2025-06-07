class Solution {
public:
    string clearStars(string s) {
        unordered_set<int> toRemove;
        unordered_map<char, vector<int>> mp;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(mp[ch].size() != 0){
                        toRemove.insert(mp[ch].back());
                        mp[ch].pop_back();
                        break;
                    }
                }
            } else {
                mp[s[i]].push_back(i);
            }
        }
        string res = "";
        for(int i = 0; i < n; i++){
            if(!toRemove.contains(i) && s[i] != '*') res += s[i];
        }
        return res;
    }
};
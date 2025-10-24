set<int> balanced;
bool flag = true;
class Solution {
public:
    void solve(set<string>& v, string s, int digit) {

        if (s.size() > 7 || digit > 7) {
            return;
        }

        if (s.size() > 0) {
            v.insert(s);
        }

        // Pick this digit
        string temp = s;
        for (int j = 1; j <= digit; j++) {
            temp += (digit + '0');
        }

        solve(v, temp, digit + 1);

        // Skip this digit
        solve(v, s, digit + 1);
    }

    void precompute() {
        set<string> v;

        solve(v, "", 1);

        for (string s : v) {
            string val = s;
            balanced.insert(stoi(s));
            while (next_permutation(val.begin(), val.end())) {
                balanced.insert(stoi(val));
            }
        }
    }
    int nextBeautifulNumber(int n) {
        if(flag){
            precompute();
            flag = false;
        }

        auto it = balanced.upper_bound(n);

        return *it;
    }
};
#define ll long long int
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map< ll, ll > mp;

        mp[0] = 1;

        ll prefixPattern = 0, ans = 0;

        for(auto c: word )
        {
            prefixPattern = ( prefixPattern ^ ( 1 << (c-'a')));

            ans += mp[prefixPattern];

            for(auto ch = 'a'; ch <= 'j'; ch++ )
            {
                ll oddPattern = ( prefixPattern ^ ( 1 << (ch - 'a')));
                ans += mp[oddPattern];
            }

            mp[prefixPattern]++;
        }

        return ans;
    }
};
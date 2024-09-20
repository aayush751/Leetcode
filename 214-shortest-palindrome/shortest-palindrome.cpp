class Solution {
public:

    vector<int> computeLPS(string& s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

    string shortestPalindrome(string s) {
        string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    // Concatenate original string and reversed string with a delimiter
    string concat = s + "#" + rev_s;

    // Compute LPS array for the concatenated string
    vector<int> lps = computeLPS(concat);

    // The part of rev_s that is not a palindrome needs to be added to the front
    string to_add = rev_s.substr(0, s.size() - lps.back());

    // Return the shortest palindrome
    return to_add + s;
    }
};
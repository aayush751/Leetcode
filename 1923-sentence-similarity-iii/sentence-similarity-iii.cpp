class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> v1, v2;
    istringstream as1(s1), as2(s2);

    string word1, word2;

    // Split both sentences into words
    while (as1 >> word1) v1.push_back(word1);
    while (as2 >> word2) v2.push_back(word2);

    int n1 = v1.size(), n2 = v2.size();
    
    // Ensure v1 is always the shorter sentence
    if (n1 > n2) {
        swap(v1, v2);
        swap(n1, n2);
    }

    // Check if all words of the shorter sentence are a prefix or suffix of the longer sentence
    int i = 0;
    while (i < n1 && v1[i] == v2[i]) i++; // Match prefix

    int j = 0;
    while (j < n1 && v1[n1 - 1 - j] == v2[n2 - 1 - j]) j++; // Match suffix

    return (i + j >= n1); 
    }
};
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
    
    // स्ट्रिंग के हर कैरेक्टर का काउंट बढ़ाएं
    for (char c : text) {
        count[c - 'a']++;
    }
    
    // "balloon" के लिए ज़रूरी अक्षरों का काउंट निकालें
    int b = count['b' - 'a'];
    int a = count['a' - 'a'];
    int l = count['l' - 'a'] / 2; // क्योंकि 2 'l' चाहिए
    int o = count['o' - 'a'] / 2; // क्योंकि 2 'o' चाहिए
    int n = count['n' - 'a'];
    
    // सबसे कम उपलब्ध अक्षर ही अधिकतम शब्द तय करेगा
    return min({b, a, l, o, n});
    }
};
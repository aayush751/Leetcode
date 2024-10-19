class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
    
    int len = (1 << n) - 1;  // Length of Sn
    int mid = len / 2 + 1;   // Position of the middle bit
    
    if (k == mid) {
        return '1';
    } else if (k < mid) {
        return findKthBit(n - 1, k);
    } else {
        k = len - k + 1;
        char bit = findKthBit(n - 1, k);
        return bit == '0' ? '1' : '0';
    }
    }
};
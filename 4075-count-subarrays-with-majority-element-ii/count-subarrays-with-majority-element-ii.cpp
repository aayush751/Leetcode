class Solution {

    private:
    vector<int> bit;
    int size;

    // Fenwick Tree में वैल्यू अपडेट करने का फंक्शन
    void update(int index, int val) {
        for (; index <= size; index += index & -index) {
            bit[index] += val;
        }
    }

    // Fenwick Tree से सम (Sum) निकालने का फंक्शन
    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += bit[index];
        }
        return sum;
    }
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // प्रीफिक्स सम -n से +n तक जा सकता है, इसलिए साइज़ 2n + 1 होगा
        size = 2 * n + 1;
        bit.assign(size + 1, 0);

        long long count = 0; // कुल सब-ऐरे गिनने के लिए
        int prefix_sum = 0;
        int offset = n + 1; // नेगेटिव इंडेक्स से बचने के लिए

        // बेस केस: शुरुआत में प्रीफिक्स सम 0 होता है
        update(0 + offset, 1);

        for (int i = 0; i < n; i++) {
            // स्टेप 1: ट्रांसफॉर्मेशन
            if (nums[i] == target) {
                prefix_sum += 1;
            } else {
                prefix_sum -= 1;
            }

            // स्टेप 2: उन प्रीफिक्स सम्स को गिनें जो वर्तमान प्रीफिक्स सम से छोटे हैं
            // (index - 1 तक क्वेरी करेंगे क्योंकि हमें strictly smaller चाहिए)
            count += query(prefix_sum + offset - 1);

            // स्टेप 3: वर्तमान प्रीफिक्स सम को BIT में ऐड करें
            update(prefix_sum + offset, 1);
        }

        return count;
    }
};
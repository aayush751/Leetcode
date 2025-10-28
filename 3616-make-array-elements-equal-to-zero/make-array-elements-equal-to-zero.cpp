class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int left = 0;
        int right = 0;
        for (int i : nums) {
            right += i;
        }

        for (int i : nums) {

            if (i==0) {
                // Left turn

                if (left >= right && left - right <= 1) {
                    count++;
                }

                // Right turn

                if (right >= left && right - left <= 1) {
                    count++;
                }
            }

            left += i;
            right -= i;
        }

        return count;
    }
};
class Solution {
public:
   vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> validRightMostIdx(n);
        //validRightMostIdx[i] = j; right most index starting from i which is a special subarray [i..j]

        int i = 0;
        int j = 0;

        while(i < n) {
            if(j < i) {
                j = i;
            }

            while(j+1 < n && nums[j]%2 != nums[j+1]%2) {
                j++;
            }

            validRightMostIdx[i] = j;
            i++;
        }


        vector<bool> result(m, false);

        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if(end <= validRightMostIdx[start]) {
                result[i] = true;
            }
        }

        return result;
    }
};
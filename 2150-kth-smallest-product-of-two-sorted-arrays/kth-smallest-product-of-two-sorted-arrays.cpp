class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while(left < right){
            long long mid = left + (right - left) / 2;
            if(countProduct(nums1, nums2, mid) < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    long long countProduct(vector<int>& nums1, vector<int>& nums2, long long u){
        long long count = 0;
        for(int num1 : nums1){
            if(num1 == 0){
                if(u >= 0) count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            while(low < high){
                int mid = (low + high) / 2;
                long long product = 1LL * num1 * nums2[mid];
                if(product <= u){
                    if(num1 > 0) low = mid+1;
                    else high = mid;
                }
                else{
                    if(num1 > 0) high = mid;
                    else low = mid+1;
                }
            }
            count += (num1 > 0)? low : (nums2.size() - low);
        }
        return count;
    }
};
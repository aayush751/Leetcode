class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector< int > ans;

        int m = nums1.size(), n = nums2.size();

        int i = 0, j = 0;

        while( i < m and j < n )
        {
            if( nums1[i] == nums2[j] )
            {
                ans.push_back( nums1[i]);
                i++;
                j++;
            }
            else if( nums1[i] < nums2[j] )
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        if( ans.size() == 0 )
        {
            return -1;
        }
        return ans[0];
    }
};
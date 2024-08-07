class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        sort(begin(nums1), end(nums1));

        sort(begin(nums2), end(nums2));

        int i = 0, j=0; 
        while( i<nums1.size() and j<nums2.size() )
        {
            if( nums1[i] == nums2[j] )
            {
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            else if( nums1[i] != nums2[j] )
            {
                if( nums1[i] > nums2[j] )
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        return v;
    }
};
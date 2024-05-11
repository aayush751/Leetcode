class Solution {
public:

    int countOfSmallerElement( vector<vector<int>>& matrix, int mid )
    {
        int count = 0;
        for(int i = 0; i < matrix.size(); i++ )
        {
            count += upper_bound( matrix[i].begin(), matrix[i].end(), mid ) - matrix[i].begin();
        }
        // ye function ye dega ki hmara assumed mid se kitna value chhota hai..taki pata lg sake kth smalles element
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // ab binary search apply kr rhe hai bina extra space lekr bnane k liye
        int n = matrix.size(), m = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][m-1];
        int mid = low + ( high - low ) / 2;

        int result = 0;
        while( low <= high )
        {
            int count = countOfSmallerElement( matrix, mid );

            if( count >= k )
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + ( high - low ) / 2;
        }

        return result;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue< int > pq;
        vector< int > ans(n);
        int k = n - 1;

        for(auto ele: nums )
        {
            pq.push( ele );
        }
        
        while( !pq.empty() )
        {
            ans[k--] = pq.top();
            pq.pop();
        }

        return ans;
    }
};
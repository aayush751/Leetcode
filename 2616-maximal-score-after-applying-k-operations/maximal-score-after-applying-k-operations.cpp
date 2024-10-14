class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue< int > pq;

        for(auto ele: nums )
        {
            pq.push( ele );
        }

        long long score = 0;

        for(int i = 0; i < k; i++ )
        {
            int maxElement = pq.top();
            pq.pop();

            score += maxElement;

            pq.push( ceil( maxElement / 3.0 ) );
        }

        return score;
    }
};
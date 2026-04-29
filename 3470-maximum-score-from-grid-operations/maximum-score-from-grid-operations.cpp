class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        
        // prefix[j][i] stores the sum of the first 'i' elements in column 'j'
        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];
            }
        }
        
        // DP arrays representing the state of the previous column (j - 1)
        vector<long long> prevPick(n + 1, 0);
        vector<long long> prevSkip(n + 1, 0);
        
        // Iterate through each column starting from the second one
        for (int j = 1; j < n; ++j) {
            vector<long long> currPick(n + 1, 0);
            vector<long long> currSkip(n + 1, 0);
            
            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    
                    if (curr > prev) {
                        // Case 1: The current column is taller than the previous column.
                        // It acts as a right neighbor and scores the white cells in the 
                        // previous column from row 'prev' to 'curr - 1'.
                        long long score = prefix[j - 1][curr] - prefix[j - 1][prev];
                        
                        // We strictly use prevSkip to ensure we don't double-count cells 
                        // in column j-1 that might have already been scored by j-2.
                        currPick[curr] = max(currPick[curr], prevSkip[prev] + score);
                        currSkip[curr] = max(currSkip[curr], prevSkip[prev] + score);
                        
                    } else {
                        // Case 2: The previous column is taller (or equal) to the current.
                        // It acts as a left neighbor and scores the white cells in the 
                        // current column from row 'curr' to 'prev - 1'.
                        long long score = prefix[j][prev] - prefix[j][curr];
                        
                        // currPick inherently accepts this left-neighbor score.
                        currPick[curr] = max(currPick[curr], prevPick[prev] + score);
                        
                        // currSkip deliberately skips this left-neighbor score, leaving the 
                        // cells available to be safely scored by column j+1 in the next loop.
                        currSkip[curr] = max(currSkip[curr], prevPick[prev]);
                    }
                }
            }
            // Move current states to previous states for the next iteration
            prevPick = move(currPick);
            prevSkip = move(currSkip);
        }
        
        // The final answer is the maximum score recorded in the last column's pick state
        long long max_score = 0;
        for (long long score : prevPick) {
            max_score = max(max_score, score);
        }
        
        return max_score;
    }
};
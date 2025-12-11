
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> x_range; // x -> {minY, maxY}
        unordered_map<int, pair<int,int>> y_range; // y -> {minX, maxX}

        // Step 1: Compute min/max for each x and y
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (!x_range.count(x)) x_range[x] = {y, y};
            else {
                x_range[x].first = min(x_range[x].first, y);
                x_range[x].second = max(x_range[x].second, y);
            }

            if (!y_range.count(y)) y_range[y] = {x, x};
            else {
                y_range[y].first = min(y_range[y].first, x);
                y_range[y].second = max(y_range[y].second, x);
            }
        }

        // Step 2: Count buildings NOT at extremes
        int count = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            bool is_extreme_x = (x_range[x].first == y || x_range[x].second == y);
            bool is_extreme_y = (y_range[y].first == x || y_range[y].second == x);

            if (!is_extreme_x && !is_extreme_y)
                count++;
        }

        return count;
    }
};
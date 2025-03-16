class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}});


        while(!q.empty()) {
            int currEffort = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if (row == n - 1 && col == m - 1) return currEffort;

            for (int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int effort = abs(heights[newRow][newCol] - heights[row][col]);
                    int maxEffort = max(currEffort, effort);

                    if(dist[newRow][newCol] > maxEffort) {
                        dist[newRow][newCol] = maxEffort;
                        q.push({maxEffort, {newRow, newCol}});
                    }
                    
                }
            }
        }
        return -1;
    }
};
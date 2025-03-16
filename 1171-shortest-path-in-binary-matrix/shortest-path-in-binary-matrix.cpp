class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = 1;
        vector<int> drow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dcol = {-1, 0, 1, 1, 1, 0, -1, -1};

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});


        while(!q.empty()) {
            int currdist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if (row == n - 1 && col == n - 1) return currdist;

            for (int i = 0; i < 8; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && dist[newRow][newCol] > currdist + 1) {
                    
                    dist[newRow][newCol] = currdist + 1;
                    q.push({dist[newRow][newCol], {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};
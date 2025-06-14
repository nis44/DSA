class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<int> delrow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> delcol = {-1, 0, 1, 1, 1, 0, -1, -1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // using grid itself as visited, mark with step count
        int steps = 1;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [r, c] = q.front();
                q.pop();
                if(r == n-1 && c == n-1) return steps;

                for(int i = 0; i < 8; i++) {
                    int nr = r + delrow[i];
                    int nc = c + delcol[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1; // mark as visited
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

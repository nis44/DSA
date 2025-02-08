class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // Traverse first and last row
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && grid[0][i] == 1) {
                q.push({0, i});
                vis[0][i] = 1;  // Mark as visited
            }
            if (!vis[m - 1][i] && grid[m - 1][i] == 1) {
                q.push({m - 1, i});
                vis[m - 1][i] = 1;  // Mark as visited
            }
        }

        // Traverse first and last column
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;  // Mark as visited
            }
            if (!vis[i][n - 1] && grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                vis[i][n - 1] = 1;  // Mark as visited
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;  // Mark as visited when pushing
                }
            }
        }

        // Count enclaves
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

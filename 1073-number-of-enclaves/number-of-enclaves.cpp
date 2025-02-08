class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, int delrow[], int delcol[]) {
                int m = grid.size();
                int n = grid[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && grid[0][i] == 1) {
                dfs(0, i, vis, grid, delrow, delcol);
            }

            if (!vis[m - 1][i] && grid[m - 1][i] == 1) {
                dfs(m-1, i, vis, grid, delrow, delcol);
            }
        }

        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid, delrow, delcol);
            }

            if (!vis[i][n - 1] && grid[i][n - 1] == 1) {
                dfs(i, n-1, vis, grid, delrow, delcol);
            }
        }

        

       

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};
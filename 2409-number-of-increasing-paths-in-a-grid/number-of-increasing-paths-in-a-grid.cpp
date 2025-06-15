class Solution {
    int mod = 1e9 + 7;
    int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        
        int m = grid.size(), n = grid[0].size();
        long res = 1;

        for(auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j]) {
                res += dfs(ni, nj, grid, dp);
                res %= mod;
            }
        }

        return dp[i][j] = res;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        long total = 0;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                total += dfs(i, j, grid, dp);
                total %= mod;
            }

        return total;
    }
};

class Solution {
    
    int mod = 1e9 + 7;
    int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

private:

    int dfs(vector<vector<int>> &grid, vector<vector<int>>&dp,  int row, int col) {
        if(dp[row][col] != -1) return dp[row][col];

        int m = grid.size();
        int n = grid[0].size();

        int res = 1;

        for(auto &it: dirs) {
            int nrow = row + it[0];
            int ncol = col + it[1];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] > grid[row][col]) {
                res = (res + dfs(grid, dp, nrow, ncol)) % mod;
            }
        }

        return dp[row][col] = res;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        long long ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = (ans + dfs(grid, dp, i, j)) % mod;
            }
        }
        return ans;
    }
};
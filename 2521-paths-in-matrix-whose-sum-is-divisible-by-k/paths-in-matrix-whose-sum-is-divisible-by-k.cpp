class Solution {
private:
    const int mod = 1e9 + 7;

    int solve(int row, int col, int sum, vector<vector<vector<int>>> &dp, vector<vector<int>>& grid, int k) {
        if (row < 0 || col < 0) return 0;

        sum = (sum + grid[row][col]) % k;

        if (row == 0 && col == 0) {
            return (sum == 0) ? 1 : 0;
        }

        if (dp[row][col][sum] != -1) return dp[row][col][sum];

        int up = solve(row - 1, col, sum, dp, grid, k);
        int left = solve(row, col - 1, sum, dp, grid, k);

        return dp[row][col][sum] = (up + left) % mod;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // 3D DP: [row][col][mod_k]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));


        return solve(m - 1, n - 1, 0, dp, grid, k);
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int down = 0, right = 0;

                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                if (i > 0)
                    down = dp[i - 1][j];
                if (j > 0)
                    right = dp[i][j - 1];

                dp[i][j] = down + right;
            }
        }

        return dp[m - 1][n - 1];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int k = amount;

        vector<vector<int>> dp(n, vector<int> (k + 1, 1e9));

        for(int i = 0; i <= k; i++) {
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                int take = 1e9;

                int skip = dp[i-1][j];

                if(coins[i] <= j) take =1+  dp[i][j - coins[i]];

                dp[i][j] = min(take, skip);
            }
        }

        if(dp[n-1][k] >= 1e9) return -1;
        else return dp[n-1][k];
    }
};
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for(int i = n-1; i >= 0; i--) {
            int sum = INT_MIN;
            int large = INT_MIN;
            int len = 0;

            for(int j = i; j < min(n, i + k); j++) {
                len++;
                large = max(large, arr[j]);
                int cost = large * len + dp[j + 1];

                sum = max(sum, cost);
            }

            dp[i] = sum;
        }

        return dp[0];
    }
};
class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    int burst(vector<int>& nums, int l, int r) {
        if (l > r) return 0; // No balloons left in this range

        if (dp[l][r] != -1) return dp[l][r]; // Return already computed result

        int maxCoins = 0;
        for (int i = l; i <= r; i++) {
            int coins = nums[l-1] * nums[i] * nums[r+1] 
                      + burst(nums, l, i-1) 
                      + burst(nums, i+1, r);
            maxCoins = max(maxCoins, coins);
        }
        return dp[l][r] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); // Add virtual balloon at start
        nums.push_back(1); // Add virtual balloon at end

        dp.assign(n+2, vector<int>(n+2, -1)); // Initialize DP table with -1

        return burst(nums, 1, n);
    }
};
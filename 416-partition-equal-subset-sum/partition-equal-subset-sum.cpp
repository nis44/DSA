class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++) sum += nums[i];

        if(sum % 2 == 1) return false;

        sum /= 2;

        vector<vector<bool>> dp(n, vector<bool> (sum + 1, 0));

        if (nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                bool nt = dp[i-1][j];

                bool t = false;

                if(nums[i] <= j) {
                    t = dp[i-1][j - nums[i]];
                }

                dp[i][j] = t + nt;



            }
        }

        return dp[n-1][sum];
    }
};
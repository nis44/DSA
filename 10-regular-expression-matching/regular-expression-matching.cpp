class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case: Empty string matches an empty pattern
        dp[0][0] = true;

        // Handle patterns like "a*", "a*b*", etc., when the string is empty
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Exclude '*' and its preceding character, or include it
                    dp[i][j] = dp[i][j - 2] || 
                               (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                }
            }
        }

        return dp[n][m];
    }
};

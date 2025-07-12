class Solution {
public:

    bool solve(int start, unordered_map<string, int> &mpp, vector<int> &dp, string s) {
        if(start == s.size()) {
            return true;
        }
        if(dp[start] != -1) return dp[start];

        for(int i = start; i < s.size(); i++) {
            string word = s.substr(start, i - start + 1);
            if(mpp.find(word) != mpp.end()) {
                if(solve(i + 1, mpp, dp, s)) return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mpp;
        for(auto it: wordDict) {
            mpp[it]++;
        }
        int n = s.size();
        vector<int> dp(n + 1, -1);

        return solve(0, mpp, dp, s);
    }
};
class Solution {
public:

    int solve(int i, unordered_map<string, int> &mpp, vector<int> &dp, string s) {
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int ntake = 1 + solve(i + 1, mpp, dp, s);
        int take = INT_MAX;
        for(int j = i; j < s.size(); j++) {
            string word = s.substr(i, j - i + 1);
            if(mpp.find(word) != mpp.end()) {
                take = min(take, solve(j + 1, mpp, dp, s));
            }
        }


        return dp[i] = min(take, ntake);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mpp;
        for(auto it: dictionary) mpp[it]++;
        int n = s.size();

        vector<int> dp(n + 1, -1);

        return solve(0, mpp, dp, s);
    }
};
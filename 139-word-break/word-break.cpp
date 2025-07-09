class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;

    bool solve(int start, string &s) {
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];

        for (int i = start; i < s.size(); i++) {
            string word = s.substr(start, i - start + 1);
            if (st.count(word)) {
                if (solve(i + 1, s)) return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp = vector<int>(s.size(), -1);
        return solve(0, s);
    }
};

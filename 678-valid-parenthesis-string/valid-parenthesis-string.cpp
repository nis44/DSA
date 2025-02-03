class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string &s, int cnt, int idx) {
        if (cnt < 0) return false; // More ')' than '(' → invalid case
        if (idx == s.size()) return cnt == 0; // Valid if balanced
        
        string key = to_string(cnt) + "," + to_string(idx);
        if (dp.find(key) != dp.end()) return dp[key];

        if (s[idx] == '(') {
            return dp[key] = solve(s, cnt + 1, idx + 1);
        } 
        else if (s[idx] == ')') {
            return dp[key] = solve(s, cnt - 1, idx + 1);
        } 
        else { // '*' can be '(', ')', or ''
            return dp[key] = (solve(s, cnt + 1, idx + 1) || solve(s, cnt - 1, idx + 1) || solve(s, cnt, idx + 1));
        }
    }

    bool checkValidString(string s) {
        dp.clear();
        return solve(s, 0, 0);
    }
};

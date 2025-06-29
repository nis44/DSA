class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        help(0 , s, ans, temp);
        return ans;
    }

    void help(int idx, string s, vector<vector<string>> &ans, vector<string> &temp) {
        if(idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i< s.size(); i++) {
            if(is(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                help(i + 1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

    bool is(string s, int st, int e) {
        while(st <= e) {
            if(s[st] != s[e]) {return false;}
            st++;
            e--;
        }

        return true;
    }
};
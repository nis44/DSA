class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<string> st;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        vector<string> temp;
        solve(0, s, temp);

        vector<string> res;
        for(auto &vec : ans) {
            string sentence = "";
            for(int i = 0; i < vec.size(); i++) {
                sentence += vec[i];
                if(i != vec.size() - 1) sentence += " ";
            }
            res.push_back(sentence);
        }

        return res;
    }

    void solve(int start, string &s, vector<string> &temp) {
        if(start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            string word = s.substr(start, i - start + 1);
            if(st.count(word)) {
                temp.push_back(word);
                solve(i + 1, s, temp);
                temp.pop_back();  // backtrack
            }
        }
    }
};
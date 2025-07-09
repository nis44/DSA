class Solution {
public:

    void solve(int str, string s, unordered_map<string, int> &mpp, vector<vector<string>> & ans, vector<string> &temp) {
        if(str == s.size()) {
            ans.push_back(temp);
            return;
        }


        for(int i = str; i < s.size(); i++) {
            string word = s.substr(str, i - str + 1);
            if(mpp.find(word) != mpp.end()) {
                temp.push_back(word);
                solve(i + 1, s, mpp, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mpp;
        for(int i = 0; i < wordDict.size(); i++) {
            mpp[wordDict[i]]++;
        }
        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, s, mpp, ans, temp);

        vector<string> res;
        for(auto &vec: ans) {
            string sen = "";
            for(int i = 0; i < vec.size(); i++) {
                sen += vec[i];
                sen += " ";
            }
            sen.pop_back();

            res.push_back(sen);
        }

        return res;
    }
};
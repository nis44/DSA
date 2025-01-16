class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    bool check(const string& str) {
        return isVowel(str.front()) && isVowel(str.back());
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans(n, 0);
        if(check(words[0])) ans[0] = 1;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + (check(words[i]) ? 1 : 0);
        }

        
        n = queries.size();
        vector<int> res(n);

        for(int i = 0; i < n; i++) {
            res[i] = ans[queries[i][1]] - ans[queries[i][0]];
            if(check(words[queries[i][0]])) res[i]++;
        }

        for(auto it : ans) cout<< it<<" ";

        return res;



    }
};
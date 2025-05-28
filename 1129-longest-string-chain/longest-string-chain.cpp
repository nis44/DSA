class Solution {
public:
    bool compare(string s1, string s2) {
        if(s1.size() != s2.size() + 1) return false;

        int a = 0;
        int b = 0;

        while(a < s1.size() && b < s2.size()) {
            if(s1[a] == s2[b]) {
                a++;
                b++;
            } else {
                a++;
            }
        }

        return b == s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(compare(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }

        // for(int i = 0; i < n; i++) {
        //     cout<<dp[i]<<" ";
        // }


        // while(hash[lastIdx] != lastIdx) {
        //     lastIdx = hash[lastIdx];
        //     temp.push_back(nums[lastIdx]);
        // }

        return maxi;




    }
};
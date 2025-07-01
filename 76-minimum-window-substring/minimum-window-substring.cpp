class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char, int> mpp;
        for(int i = 0; i < t.size(); i++) {
            mpp[t[i]]++;
        }

        int l = 0, r = 0, cnt = 0;
        int mini = 1e9;
        int str = -1;

        while(r < s.size()) {
            if(mpp[s[r]] > 0) {
                cnt++;
                
            }
            mpp[s[r]]--;

            while(cnt == t.size()) {
                if(mini > r - l + 1) {
                    mini = r - l + 1;
                    str = l;
                }

                mpp[s[l]]++;
                

                if(mpp[s[l]] > 0) cnt--;
                l++;
            }

            r++;
        }

        return str == -1 ? "" : s.substr(str, mini);

        
    }
};
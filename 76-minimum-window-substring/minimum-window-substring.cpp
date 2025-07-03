class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < t.size(); i++) {
            mpp[t[i]]++;
        }

        int l = 0, r = 0, mini = 1e9, cnt = 0;
        int sidx = -1;

        while(r < s.size()) {
            if(mpp[s[r]] > 0) {
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt == t.size()) {
                // mini = min(mini, r - l + 1);
                // sidx = l;
                if(mini > r - l + 1) {
                    mini = r - l + 1;
                    sidx = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
                
            }

            

            r++;
        }

        return sidx == -1 ? "" : s.substr(sidx, mini);
    }
};
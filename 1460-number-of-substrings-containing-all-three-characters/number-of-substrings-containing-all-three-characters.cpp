class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> seen(3, -1);
        int cnt = 0;

        int r = 0;
        while(r < s.size()) {
            seen[s[r] - 'a'] = r;

            if(seen[0] != -1 && seen[1] != -1 && seen[2] != -1) {
                cnt += 1 + min({seen[0], seen[1], seen[2]});
            }
            r++;
        }
        return cnt;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int r = 0, l = 0, max_freq = 0, max_len = 0;

        while (r < n) {
            mpp[s[r]]++;
            max_freq = max(max_freq, mpp[s[r]]);

            if (r - l + 1 - max_freq > k) {
                mpp[s[l]]--;
                l++;
            }
                max_len = max(max_len, r - l + 1);
            

            r++;
        }

        return max_len;
    }
};

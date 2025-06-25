class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int left = 0;
        int maxi = 0;
        int n = s.size();

        unordered_map<char, int> mpp;

        while(right < n) {

            
            if(mpp.find(s[right]) != mpp.end()) {
                if(mpp[s[right]] >= left) {
                    left = mpp[s[right]] + 1;
                }
            }
            maxi = max(maxi, right - left + 1);

            mpp[s[right]] = right;
            right++;

            
        }

        return maxi;
    }
};
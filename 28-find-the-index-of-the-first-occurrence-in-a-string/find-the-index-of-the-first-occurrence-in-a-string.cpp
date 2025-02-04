class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int i = 0;
        while(r < haystack.size()) {
            if(haystack[r] == needle[i]) {
                i++;
                r++;
                cnt++;
                if(cnt == needle.size()) return l;
            }
            else {
                l++;
                r = l;
                i = 0;
                cnt = 0;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        char prev1;
        char prev2;
        char curr1, curr2;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                if(cnt == 0) {
                    prev1 = s1[i];
                    prev2 = s2[i];
                }
                else if(cnt == 1) {
                    curr1 = s1[i];
                    curr2 = s2[i];
                }
                cnt++;
            }
        }
        cout<<cnt;

        if(cnt == 2 && prev1 == curr2 && prev2 == curr1) return true;
        return false;
    }
};
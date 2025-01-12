class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n % 2 == 1) return false;

        int ocnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || locked[i] == '0') ocnt++;
            else if(s[i] == ')' && locked[i] == '1') ocnt--;

            if(ocnt < 0) return false;
        }
        int ccnt = 0;

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ')' || locked[i] == '0') ccnt++;
            else if(s[i] == '(' && locked[i] == '1') ccnt--;

            if(ccnt < 0) return false;
        }

        return true;
    }
};
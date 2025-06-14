class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char toMax = 0, toMin = 0;
        int n = s.size();
        for (char c : s) {
            if (c != '9') {
                toMax = c;
                break;
            }
        }
        
        for (char c : s) {
            if (c != '0') {
                toMin = c;
                break;
            }
        }

        string maxStr = s, minStr = s;
        for (char &c : maxStr) {
            if (c == toMax) c = '9';
        }
        for (char &c : minStr) {
            if (c == toMin) c = '0';
        }

        return stoi(maxStr) - stoi(minStr);
    }
};

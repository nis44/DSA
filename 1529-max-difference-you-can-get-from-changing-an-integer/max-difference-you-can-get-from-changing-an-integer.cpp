class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        int maxi = num, mini = num;

        for (char x = '0'; x <= '9'; x++) {
            for (char y = '0'; y <= '9'; y++) {
                if (x == y) continue;

                string temp = s;
                for (char &c : temp) {
                    if (c == x) c = y;
                }

                if (temp[0] == '0') continue; // leading zero not allowed

                int val = stoi(temp);
                maxi = max(maxi, val);
                mini = min(mini, val);
            }
        }

        return maxi - mini;
    }
};
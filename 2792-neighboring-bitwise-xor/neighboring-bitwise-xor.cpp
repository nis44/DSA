class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int xoR = 0;
        for(int i = 0; i < n; i++) {
            xoR ^= derived[i];
        }
        return xoR == 0;
    }
};
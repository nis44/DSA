class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top = 0;
        for(int i = 0; i < n; i++) {
            top += grid[0][i];
        }

        long long down = 0;
        long long res = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            top -= grid[0][i];
            res = min(res, max(top, down));
            down += grid[1][i];
        }

        return res;
    }
};
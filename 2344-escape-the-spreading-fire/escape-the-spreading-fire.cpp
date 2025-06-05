class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> fire(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                    fire[i][j] = 0;
                }
            }
        }

        vector<int> delrow = {-1, 0, 1, 0}, delcol = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = delrow[i] + r;
                int ncol = delcol[i] + c;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol] && grid[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = true;
                    fire[nrow][ncol] = t + 1;
                }
            }
        }

        int ans = -1, start = 0, end = n * m + 1;

        while(start <= end) {
            int mid = (start + end) >> 1;
            if(possible(grid, fire, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans >= n * m ? (int)1e9 : ans;
    }

private:
    bool possible(vector<vector<int>>& grid, vector<vector<int>>& fire, int waitTime) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        if(fire[0][0] != -1 && waitTime >= fire[0][0]) return false;

        q.push({{0, 0}, waitTime});
        vis[0][0] = true;

        vector<int> delrow = {-1, 0, 1, 0}, delcol = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [pos, t] = q.front(); q.pop();
            int r = pos.first, c = pos.second;

            if(r == n - 1 && c == m - 1) {
                if(fire[r][c] == -1 || t <= fire[r][c]) return true;
                else return false;
            }

            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                int arriveTime = t + 1;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol] && grid[nrow][ncol] == 0) {

                    if(fire[nrow][ncol] == -1 || arriveTime < fire[nrow][ncol] ||
                      (nrow == n - 1 && ncol == m - 1 && arriveTime == fire[nrow][ncol])) {
                        vis[nrow][ncol] = true;
                        q.push({{nrow, ncol}, arriveTime});
                    }
                    if(r == n - 1 && c == m - 1) {
                        if(fire[r][c] == -1 || t <= fire[r][c]) return true;
                    }
                }
            }
        }

        return false;
    }
};

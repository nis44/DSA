class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && vis[i][0] != true) {
                q.push({i, 0});
                vis[i][0] = true;
            }
            if(board[i][m-1] == 'O' && vis[i][m-1] != true) {
                q.push({i, m-1});
                vis[i][m-1] = true;
            }
            
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                q.push({0, i});
                vis[0][i] = true;
            }
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                q.push({n - 1, i});
                vis[n - 1][i] = true;
            }
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, +1, 0, -1};

            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }


    }
};
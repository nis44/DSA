class Solution {
private:

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }


public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};


        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, vis, board, delrow, delcol);
            } 

            if(board[m-1][i] == 'O' && !vis[m-1][i]) {
                dfs(m-1, i, vis, board, delrow, delcol);
            }
        }

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, board, delrow, delcol);
            } 

            if(board[i][n-1] == 'O' && !vis[i][n-1]) {
                dfs(i, n-1, vis, board, delrow, delcol);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        



    }
};
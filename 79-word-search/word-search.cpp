class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0}, dcol = {0, 0, 1, -1};
    int m, n;
    vector<vector<int>> visited;
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        // if(m == 1 && n == 1 && board[m][n] == word) return true;
        if (m == 1 && n == 1 && word.length() == 1 && board[0][0] == word[0]) return true;
        
        visited = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (help(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool help(int i, int j, vector<vector<char>>& board, string& word,
              int idx) {
        if (idx == word.length())
            return true;
        // if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j]
        // != word[idx]) return false;

        // visited[i][j] = 1;

        // for(int d = 0; d < 4; ++d) {
        //     int ni = i + drow[d];
        //     int nj = j + dcol[d];
        //     if(help(ni, nj, board, word, idx + 1)) return true;
        // }

        // visited[i][j] = 0;
        // return false;

        for (int d = 0; d < 4; ++d) {
            int ni = i + drow[d];
            int nj = j + dcol[d];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[i][j] && board[i][j] == word[idx]) {
                visited[i][j] = 1;
                if (help(ni, nj, board, word, idx + 1)) return true;
                visited[i][j] = 0;
            }
            
        }

        return false;
    }
};
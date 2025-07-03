class Solution {
public:


    void solve(int col, int n, vector<int> &udiag, vector<int> &ldiag, vector<int> &left, vector<vector<string>> &ans, vector<string> &temp, int &cnt) {
        if(col == n) {
            ans.push_back(temp);
            cnt++;
            return;
        }

        for(int i = 0; i< n; i++) {
            if(left[i] == 0 && udiag[n - 1 + i - col] == 0 && ldiag[i + col] == 0) {
                left[i] =  1;
                ldiag[i + col] = 1;
                udiag[n - 1 + i - col] = 1;
                temp[i][col] = 'Q';
                solve(col + 1, n, udiag, ldiag, left, ans, temp, cnt);
                left[i] =  0;
                ldiag[i + col] = 0;
                udiag[n - 1 + i - col] = 0;
                temp[i][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        int cnt = 0;

        vector<int> udiag(2 * n - 1), ldiag(2 * n - 1), left(n, 0);

        solve(0, n, udiag, ldiag, left, ans, temp, cnt);

        return ans.size(); 
    }
};
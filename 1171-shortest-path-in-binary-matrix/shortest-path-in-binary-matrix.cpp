class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = 1;
        vector<int> delrow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> delcol = {-1, 0, 1, 1, 1, 0, -1, -1};

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        while(!q.empty()) {
            int currdist = q.front().first;

            int row = q.front().second.first;

            int col = q.front().second.second;

            q.pop();

            if(row == n-1 && col == n-1) return currdist;

            for(int i = 0; i < 8; i++) {
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && 
                dist[nrow][ncol] > currdist + 1) {
                   dist[nrow][ncol] = currdist + 1; 
                   q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
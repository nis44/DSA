class DisjointSet {
    

public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<int, pair<int, int>>> cells;
        int n = grid.size();

        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < n ; j++) {
                cells.push_back({grid[i][j], {i, j}});
            }
        }

        sort(cells.begin(), cells.end());

        DisjointSet ds(n * n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};

        for (auto &[elevation, pos] : cells) {
            int row = pos.first;
            int col = pos.second;
            vis[row][col] = true;
            int node = row * n + col;

            for (int k = 0; k < 4; k++) {
                int nr = row + dx[k];
                int nc = col + dy[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && vis[nr][nc]) {
                    int adj = nr * n + nc;
                    ds.unionBySize(node, adj);
                }
            }

            if (ds.findUPar(0) == ds.findUPar(n * n - 1)) {
                return elevation;
            }
        }

        return -1;
    }
};
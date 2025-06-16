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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<int> delrow = {-1, 0, 1, 0}, delcol = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nrow = delrow[k] + i;
                    int ncol = delcol[k] + j;

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
                        grid[nrow][ncol] == 1) {
                        int node = i * n + j;
                        int adnode = nrow * n + ncol;
                        ds.unionBySize(node, adnode);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;
                unordered_set<int> stt;

                for (int k = 0; k < 4; k++) {
                    int nrow = delrow[k] + i;
                    int ncol = delcol[k] + j;

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
                        grid[nrow][ncol] == 1) {
                        int node = i * n + j;
                        int adnode = nrow * n + ncol;
                        int upar = ds.findUPar(adnode);
                        stt.insert(upar);
                    }
                }

                int sum = 1;

                for (auto it : stt) {
                    sum += ds.size[it];
                }

                ans = max(ans, sum);
            }
        }

        for(int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }

        return ans;
    }
};
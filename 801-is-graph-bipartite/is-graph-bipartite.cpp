class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                queue<pair<int, int>> q;
                q.push({i, 0});
                vis[i] = 0;

                while (!q.empty()) {
                    int node = q.front().first;
                    int color = q.front().second;
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (vis[neighbor] == -1) {
                            vis[neighbor] = 1 - color;
                            q.push({neighbor, 1 - color});
                        } else if (vis[neighbor] == color) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
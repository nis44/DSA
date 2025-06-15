class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currTime > dist[node]) continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeTime = it.second;
                long long newTime = currTime + edgeTime;

                if (newTime < dist[adjNode]) {
                    dist[adjNode] = newTime;
                    ways[adjNode] = ways[node];
                    pq.push({newTime, adjNode});
                } else if (newTime == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};

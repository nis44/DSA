class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); 
        
        for (const auto& flight : flights) {
            int u = flight[0], v = flight[1], cost = flight[2];
            adj[u].push_back({v, cost});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX); 
        dist[src] = 0;

        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();

            for(auto it: adj[node]) {
                int adnode = it.first;
                int edwt = it.second;

                if(cost + edwt < dist[adnode] && stops <= k) {
                    dist[adnode] = cost + edwt;
                    q.push({stops + 1, {adnode, dist[adnode]}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
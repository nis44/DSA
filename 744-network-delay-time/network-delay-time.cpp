class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it: times) {
            int u = it[0];
            int v = it[1];
            int time = it[2];


            adj[u].push_back({v, time});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]) {
                int adnode = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[adnode]) {
                    dist[adnode] = dist[node] + wt;
                    pq.push({dist[node] + wt, adnode});
                }
            }
        }

        int maxTime = *max_element(dist.begin() + 1, dist.end());
        return (maxTime == INT_MAX) ? -1 : maxTime;

    }
};
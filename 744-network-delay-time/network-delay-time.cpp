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
            int currtime = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it: adj[node]) {
                int adnode = it.first;
                int time = it.second;
                
                if(dist[adnode] > currtime + time) {
                    dist[adnode] = currtime + time;
                    pq.push({dist[adnode], adnode});
                }
            }
        }
        int maxi = INT_MIN;

        for(int i = 1; i <= n; i++) {
            maxi = max(maxi, dist[i]);
        }

        if(maxi == INT_MAX) return -1;
        return maxi;
    }
};
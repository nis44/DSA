class DisjointSet {
    vector<int> rank, parent, size;  // Added 'size' for union by size
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);  // Initialize all sizes to 1
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])  
            return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;  

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;  
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;  

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                } else {
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }

        vector<vector<string>> mergedList(n);

        for(auto it: mpp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedList[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(mergedList[i].size() == 0) continue;
            sort(mergedList[i].begin(), mergedList[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);
            for(auto it: mergedList[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
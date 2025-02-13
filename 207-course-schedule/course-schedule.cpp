class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        return topologicalSort(numCourses, adj);
    }

private:
    bool topologicalSort(int numCourses, vector<int> adj[]) {
        vector<int> indegree(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++; 
            

            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) 
                    q.push(it);
            }
        }

        return count == numCourses;
    }
};

class Solution {
private: 

    void solve(int node, vector<vector<int>> &graph, vector<vector<int>>& ans, vector<int> &temp)  {
        temp.push_back(node);

        if(node == graph.size() - 1) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        for(auto it: graph[node]) {
            solve(it, graph, ans, temp);
        }

        temp.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, graph, ans, temp);

        return ans;

    }
};
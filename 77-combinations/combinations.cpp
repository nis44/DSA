class Solution {
public:

    void help(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int start) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            help(ans, temp, k, n, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(ans, temp, k, n, 1);
        return ans;
    }
};
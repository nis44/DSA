class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        help(k, n, ans, temp, 1);
        return ans;
    }

    void help(int k, int sum, vector<vector<int>> &ans, vector<int> temp, int start) {
        if(k == 0) {
            if(sum == 0) {
                ans.push_back(temp);
            }
            return;
        }

        for(int i = start; i <= 9; i++) {
            temp.push_back(i);
            help(k - 1, sum - i, ans, temp, i + 1);
            temp.pop_back();
        }
    }
};
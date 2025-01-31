class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>& arr, vector<bool>& used) {
        if (arr.size() == nums.size()) {
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {  
                used[i] = true;
                arr.push_back(nums[i]);

                solve(ans, nums, arr, used);
                arr.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        vector<bool> used(nums.size(), false);  
        solve(ans, nums, arr, used);
        return ans;
    }
};

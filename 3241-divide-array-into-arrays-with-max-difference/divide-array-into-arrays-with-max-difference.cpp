class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        vector<int> temp;

        for(int i = 0; i < n; i += 3) {
            if(i + 2 < n && nums[i+2] - nums[i] <= k) {
                temp = {nums[i], nums[i+1], nums[i+2]};
                ans.push_back(temp);
            }else {
                return {};
            }
        }
        return ans;
    }
};
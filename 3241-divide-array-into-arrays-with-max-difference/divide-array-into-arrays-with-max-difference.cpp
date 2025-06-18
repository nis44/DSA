class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> temp;

        for(int i = 0; i < n; i += 3) {
            if(nums[i+1] - nums[i] <= k && nums[i+2] - nums[i+1] <= k && nums[i+2] - nums[i] <= k) {
                temp = {nums[i], nums[i+1], nums[i+2]};
                ans.push_back(temp);
            }else {
                return {};
            }
        }
        return ans;
    }
};

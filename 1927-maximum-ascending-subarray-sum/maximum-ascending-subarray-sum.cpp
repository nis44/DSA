class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int max_sum = INT_MIN;
        max_sum = max(sum, max_sum);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
                max_sum = max(sum, max_sum);
            }
            else {
                sum = nums[i];
            }
        }
        return max_sum;
    }
};
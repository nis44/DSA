class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] < nums[j]) maxi = max(maxi, nums[j] - nums[i]);
            }
        }

        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};

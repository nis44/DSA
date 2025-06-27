class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int change = 0;

        int l = 0, r = 0, maxi = 0;

        while(r < n) {
            if(nums[r] == 0) change++;
            if(change > k) {
                if(nums[l] == 0) change--;
                l++;
            }

            if(change <= k) {
                
                maxi = max(maxi, r - l + 1);

            }

            r++;

        }

        return maxi;
    }
};
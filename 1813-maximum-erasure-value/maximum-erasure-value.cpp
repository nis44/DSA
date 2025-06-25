class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, maxi = 0;

        unordered_map<int, int> mpp;

        int n = nums.size();
        int sum = 0;

        while(r < n) {

            

            if(mpp.find(nums[r]) != mpp.end()) {
                if(mpp[nums[r]] >= l) {
                    while(l <= mpp[nums[r]]) {
                        sum -= nums[l];
                        l++;
                    }
                }
            }
            

            mpp[nums[r]] = r;
            sum += nums[r];
            r++;

            maxi = max(sum, maxi);



        }

        return maxi;
    }
};
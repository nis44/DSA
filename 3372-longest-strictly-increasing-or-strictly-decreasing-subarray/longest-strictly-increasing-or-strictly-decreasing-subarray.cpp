class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr = 1;
        int decs = 1;

        int max_desc = 1, max_incr = 1;



        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) {
                decs++;
                max_desc = max(decs, max_desc);
            }
            else {
                decs = 1;
            }
            
            if(nums[i - 1] < nums[i]) {
                incr++;
                max_incr = max(incr, max_incr);
            }

            else {
                incr = 1;
            }
        }

        return max(max_incr, max_desc);
    }
};
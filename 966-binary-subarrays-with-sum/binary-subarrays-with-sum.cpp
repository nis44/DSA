class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }

private:
    int countAtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int l = 0, sum = 0, count = 0;
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l++];
            }
            count += r - l + 1;
        }
        return count;
    }
};

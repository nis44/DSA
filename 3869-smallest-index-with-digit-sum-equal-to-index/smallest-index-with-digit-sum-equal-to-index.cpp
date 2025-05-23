class Solution {
public:
    int helper(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int ans = -1;

        for(int i = 0; i < nums.size(); i++) {
            int sum = helper(nums[i]);
            if(sum == i) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

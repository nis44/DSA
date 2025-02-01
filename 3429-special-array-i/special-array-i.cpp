class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag = true;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] % 2 == nums[i-1] % 2) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
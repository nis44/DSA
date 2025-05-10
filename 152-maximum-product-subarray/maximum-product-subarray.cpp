class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        long long maxProd = nums[0];
        long long minProd = nums[0];
        long long result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max((long long)nums[i], maxProd * nums[i]);
            minProd = min((long long)nums[i], minProd * nums[i]);

            result = max(result, maxProd);
        }

        return static_cast<int>(result);
    }
};
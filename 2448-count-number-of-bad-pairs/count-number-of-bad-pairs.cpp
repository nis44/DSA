class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        long long cnt = 0;
        long long tot_pair = (1LL * n * (n - 1)) / 2;

        for(int i = 0; i < n; i++) {
            cnt += mpp[nums[i] - i];
            mpp[nums[i] - i]++;
        }

        return tot_pair - cnt;
    }
};
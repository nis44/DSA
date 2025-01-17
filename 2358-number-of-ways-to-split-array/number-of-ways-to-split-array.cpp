class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long  sum = nums[0];
        vector<long long> ps(n, 0);
        ps[0] = nums[0];
        for(int i = 1; i < n; i++) {
            ps[i] = ps[i-1] + nums[i];
            sum += nums[i];
        }

        long long cnt = 0;
        for(int i = 0; i < n-1; i++) {
            long long rem_sum = sum - ps[i];
            if(ps[i] >= rem_sum) cnt++;
        }
        return cnt;
    }
};
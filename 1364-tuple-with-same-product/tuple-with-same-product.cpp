class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                mpp[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        int cnt = 0;
        for(auto it: mpp) {
            if(it.second >= 2) {
                cnt = 0;
                cnt += (it.second * (it.second - 1)) / 2;
                cnt *= 8;
                ans += cnt;
            }
            
        }
        return ans;
    }
};
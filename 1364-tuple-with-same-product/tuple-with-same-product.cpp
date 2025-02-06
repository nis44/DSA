class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) { 
                mpp[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(auto it: mpp) {
            int freq = it.second;
            if(freq >= 2) {
                ans += (freq * (freq - 1)) / 2 * 8;
            }
        }
        return ans;
    }
};

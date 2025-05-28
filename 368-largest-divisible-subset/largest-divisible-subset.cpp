class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> hash(n);

        vector<int> dp(n, 1);
        int maxi = 1;
        int lastIdx = 0;

        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIdx = i;
            }
        }

        for(int i = 0; i < n; i++) {
            cout<<dp[i]<<" ";
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);


        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }





        return temp;
    }
};
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mpp;

        int maxi = INT_MIN;


        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int sumDigi = 0;
            while (temp) sumDigi += temp % 10, temp /= 10;

            auto&p = mpp[sumDigi];
            if (nums[i] > p.first) {
                p.second = p.first;
                p.first = nums[i];
            } else if (nums[i] > p.second) {
                p.second = nums[i];
            }


        }

        for(auto it: mpp) {
            
            if (it.second.second > 0) { 
                maxi = max(maxi, it.second.first + it.second.second);
            }
        }
        return (maxi == INT_MIN) ? -1 : maxi;
    }
};
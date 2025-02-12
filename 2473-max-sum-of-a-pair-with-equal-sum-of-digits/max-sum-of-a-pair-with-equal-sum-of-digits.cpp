class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;

        int maxi = INT_MIN;


        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int sumDigi = 0;
            while (temp) sumDigi += temp % 10, temp /= 10;

            mpp[sumDigi].push_back(nums[i]);


        }

        for(auto it: mpp) {
            
            vector<int> arr = it.second;
            if (arr.size() < 2) continue;
            sort(arr.begin(), arr.end());
            int n = arr.size();
            maxi = max(arr[n-1] + arr[n-2], maxi);
        }
        return (maxi == INT_MIN) ? -1 : maxi;
    }
};
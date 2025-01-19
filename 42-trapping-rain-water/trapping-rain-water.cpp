class Solution {
public:

    vector<int> left(vector<int> &arr, int n) {
        vector<int> ans(n);
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);  
            ans[i] = maxi;     
        }

        return ans;
    }
    
    vector<int> right(vector<int> &arr, int n) {
        vector<int> ans(n);
        int maxi = 0;
        for(int i = n-1; i >= 0; i--) {
            maxi = max(maxi, arr[i]);  
            ans[i] = maxi; 
        }

        return ans;
    }

    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> leftM = left(height, n);
        vector<int> rightM = right(height, n);

        for(int i = 0; i < n; i++) {
            ans += min(leftM[i], rightM[i]) - height[i];
        }

        return ans;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k-1);
    }

    int help(vector<int>  &arr, int k) {
        int n = arr.size();

        int l = 0 , r = 0, cnt = 0, sum = 0;

        while(r < n) {
            if(arr[r] % 2 == 1) cnt++;

            while(cnt > k) {
                if(arr[l] % 2 == 1) cnt--;
                l++;
            }

            sum += r - l + 1;
            r++;
        }

        return sum;
    }
};
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int num_b = 0;
        int num_a = 0;

        if(nums1.size() % 2 != 0) {
            for(auto num: nums2) {
                num_a ^= num;
            }
        }

        if(nums2.size() % 2 != 0) {
            for(auto num: nums1) {
                num_b ^= num;
            }
        }

        return num_a ^ num_b;




    }
};
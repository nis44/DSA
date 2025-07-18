class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int n = nums2.size();
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if(st.empty()) mpp[nums2[i]] = -1;

            else {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> res;

        for(int i = 0; i < nums1.size(); i++) {
            res.push_back(mpp[nums1[i]]);
        }

        return res;
    }
};
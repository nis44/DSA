class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int , int> mpp;
        vector<int> ans(n);
        // ans[0] = 0;
        // ans[n-1] = n;
        // mpp[A[0]]++;
        // mpp[B[0]]++;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            

            if(A[i] == B[i]) cnt++;
            else {
                if(mpp.find(A[i]) != mpp.end()) cnt++;
                if(mpp.find(B[i]) != mpp.end()) cnt++;
            }

            mpp[A[i]]++;
            mpp[B[i]]++;

            ans[i] = cnt;
        }     

        return ans;   

    }
};
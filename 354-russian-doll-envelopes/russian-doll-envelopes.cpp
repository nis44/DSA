class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0];                  
        });
        vector<int> heights;
        for (auto& e : envelopes) {
            heights.push_back(e[1]);
        }


        vector<int> lis;
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), heights[i]);

            if(it == lis.end()) {
                lis.push_back(heights[i]);
            } else {
                *it = heights[i];
            }
        }
       

        return lis.size();
    }
};

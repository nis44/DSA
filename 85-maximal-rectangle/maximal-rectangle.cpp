class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pf(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == '0') {
                    pf[j][i] = 0;
                } else {
                    if (j == 0) {
                        pf[j][i] = 1;
                    } else {
                        pf[j][i] = pf[j - 1][i] + 1;
                    }
                }
            }
        }

        int maxi = 0;

        for (int i = 0; i < m; i++) {
            maxi = max(maxi, check(pf[i]));
        }

        return maxi;
    }

    vector<int> pse(vector<int> heights) {
        vector<int> left(heights.size(), -1);
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }

    vector<int> nse(const vector<int>& heights) {
        vector<int> right(heights.size(), heights.size());
        stack<int> s;
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        return right;
    }
    int check(vector<int>& maxi) {
        vector<int> nse_ = nse(maxi);
        vector<int> pse_ = pse(maxi);
        int max_area = 0;

        for (int i = 0; i < maxi.size(); i++) {
            int width = nse_[i] - pse_[i] - 1; 
            int area = maxi[i] * width;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
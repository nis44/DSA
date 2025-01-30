class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int suml = 0;
        int sumr = 0;
        for(int i = 0; i < k; i++) {
            suml += cardPoints[i];
        }

        int l = k-1;
        int r = n-1;

        int max_sum = suml;

        while(l >= 0) {
            max_sum = max(max_sum, suml + sumr);

            suml -= cardPoints[l];
            sumr += cardPoints[r];
            l--;
            r--;
        }
        max_sum = max(max_sum, suml + sumr);

        return max_sum;
    }
};
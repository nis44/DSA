class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        int n = hand.size();

        map<int, int> mpp;

        for (auto it : hand) {
            mpp[it]++;
        }

        for (int i = 0; i < n; i++) {
            int val = hand[i];

            if(mpp[val] == 0) continue;

            mpp[val]--;
            for (int i = 1; i < groupSize; i++) {
                    if (mpp.find(val + i) == mpp.end()) return false;
                    mpp[val + i]--;
                    if(mpp[val + i] == 0) mpp.erase(val + i);
                }
        }

        return true;
    }
};
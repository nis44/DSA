class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p = 0;
        int t = 0;
        int cnt = 0;

        while(t < trainers.size() && p < players.size()) {
            if(players[p] <= trainers[t]) {
                p++;
                t++;
                cnt++;
            } else {
                t++;
            }
        }
        return cnt;
    }
};
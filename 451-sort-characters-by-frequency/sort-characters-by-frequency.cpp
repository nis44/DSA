class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<int, char>> vec;
        for (auto it : freq) {
            vec.push_back({it.second, it.first});
        }
        sort(vec.rbegin(), vec.rend());

        string result;
        for (auto it : vec) {
            result.append(it.first, it.second); // Append char 'first' times
        }
        
        return result;


    }
};
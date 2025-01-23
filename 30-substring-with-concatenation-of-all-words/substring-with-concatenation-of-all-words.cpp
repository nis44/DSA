class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        if (n == 0 || s.empty()) return {};

        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        int len = words[0].size(); // Length of each word
        int totalLen = len * n;    // Total length of concatenated words
        vector<int> res;

        for (int i = 0; i < len; i++) { 
            int left = i, right = i, count = 0; // Sliding window pointers
            unordered_map<string, int> mpp;

            while (right + len <= s.size()) {
                string currword = s.substr(right, len);
                right += len; 

                if (freq.count(currword)) {
                    mpp[currword]++;
                    count++;

                    // If the word is used more than needed, shrink the window
                    while (mpp[currword] > freq[currword]) {
                        string leftword = s.substr(left, len);
                        mpp[leftword]--;
                        count--;
                        left += len;
                    }

                    // If all words are used exactly once
                    if (count == n) {
                        res.push_back(left);
                    }
                } else { 
                    // If the word is not in `words`, reset the window
                    mpp.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return res;
    }
};

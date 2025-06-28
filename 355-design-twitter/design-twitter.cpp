class Twitter {
public:
    int timestamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> list of {timestamp, tweetId}

    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        // Max-heap to collect all relevant tweets
        priority_queue<pair<int, int>> maxHeap;

        // Include self in follow list
        follows[userId].insert(userId);

        for (int followee : follows[userId]) {
            auto& tw = tweets[followee];
            for (int i = max(0, (int)tw.size() - 10); i < tw.size(); ++i) {
                maxHeap.push(tw[i]); 
            }
        }

        // Extract top 10 most recent tweets
        vector<int> result;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }

        return result; // Already in correct order (most recent first)
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

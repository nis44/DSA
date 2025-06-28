class MedianFinder {
public:
    priority_queue<int> first; 
    priority_queue<int, vector<int>, greater<int>> sec;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.empty() || first.top() > num) first.push(num);
        else sec.push(num);

        if(first.size() > sec.size() + 1) {
            sec.push(first.top());
            first.pop();
        }

        else if(first.size() + 1 < sec.size()) {
            first.push(sec.top());
            sec.pop();
        }
    }
    
    double findMedian() {
        if(first.size() == sec.size()) return  first.empty() ? 0 : (first.top() + sec.top()) / 2.0;
        return first.size() > sec.size() ? first.top() : sec.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
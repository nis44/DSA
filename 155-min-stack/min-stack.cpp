class MinStack {
public:
stack<pair<int, int>> st;
        int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push({val, min(mini, val)});
        mini = min(mini, val);
    }
    
    void pop() {
        st.pop();
        if(st.empty()) {
            mini = INT_MAX;
        } else {
            mini = st.top().second;
        }
    }
    
    int top() {
        int val = st.top().first;
        return val;
    }
    
    int getMin() {
        int val = st.top().second;
        return val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
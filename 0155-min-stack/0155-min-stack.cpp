class MinStack {
private:
    stack<int> sta1;
    stack<int> sta2;
public:
    

    MinStack() {
        
    }
    
    void push(int value) {
        sta1.push(value);
        if(sta2.empty() || sta2.top() >= value) sta2.push(value);
    }
    
    void pop() {
        if(sta1.top() == sta2.top()) sta2.pop();
        sta1.pop();
        
    }
    
    int top() {
        return sta1.top();
    }
    
    int getMin() {
        return sta2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
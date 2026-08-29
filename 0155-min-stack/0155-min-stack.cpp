class MinStack {
public:
    stack<pair<int,int>> minstack;
    MinStack() {
        
    }
    
    void push(int value) {
        if(minstack.empty() || value < minstack.top().second) minstack.push({value,value});
        else minstack.push({value,minstack.top().second});
    }
    
    void pop() {
        minstack.pop();
    }
    
    int top() {
        return minstack.top().first;
    }
    
    int getMin() {
        return minstack.top().second;
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
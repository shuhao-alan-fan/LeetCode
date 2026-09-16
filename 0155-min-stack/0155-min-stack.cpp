class MinStack {
public:
    
    stack<pair<int,int>> min_stack;

    MinStack() {
        
    }
    
    void push(int value) {
        if(min_stack.empty()) min_stack.push({value,value});
        else{
            min_stack.push({value, min(value, min_stack.top().second)});
        }

    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
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
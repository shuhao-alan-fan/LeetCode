// O(1)怎么可能呢，所有都是O(1)的话没办法push和pop的同时留住min

class MinStack {
private: 
    stack<pair<int,int>> s;
public:
    
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()) s.push(make_pair(value, value));
        else{
            int min_val = min(value, s.top().second);
            s.push(make_pair(value, min_val));
        }

    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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
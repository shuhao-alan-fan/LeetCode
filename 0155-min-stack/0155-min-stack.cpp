class MinStack {
public:
    struct minStack{
        stack<int> s;
        stack<int> min_s;
    };
    
    minStack* ms;
    MinStack() {
        this->ms = new minStack();
    }
    
    void push(int val) {
        this->ms->s.push(val);
        
        if(this->ms->min_s.empty() || val <= this->ms->min_s.top()){
            
            this->ms->min_s.push(val);
            
        }
    
    }
    //fix this
    void pop() {
        int temp = this->ms->s.top();
        if(!this->ms->min_s.empty() && this->ms->min_s.top() == temp){
            this->ms->min_s.pop();
        }
        this->ms->s.pop();
    }
    
    int top() {
        return this->ms->s.top();
    }
    
    int getMin() {
        return this->ms->min_s.top();
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
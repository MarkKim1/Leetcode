class MinStack {
public:
    int minimum = INT_MAX;
    stack<pair<int,int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(make_pair(val,val));
            return;
        }
        auto curr = stk.top();
        stk.push(make_pair(val,min(val,curr.second)));
        
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        auto curr = stk.top();
        return curr.first;
    }
    
    int getMin() {
        auto curr = stk.top();
        return curr.second;
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
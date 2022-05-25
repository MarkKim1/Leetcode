class MaxStack {
public:
    stack<int>stk;
    stack<int> maxStack;
    
    MaxStack() {
        
    }
    
    void push(int x) {
        int max = maxStack.empty() ? x : maxStack.top();
        maxStack.push(x > max ? x : max);
        stk.push(x);
    }
    
    int pop() {
        maxStack.pop();
        int a = stk.top();
        stk.pop();
        return a;
    }
    
    int top() {
        return stk.top();
    }
    
    int peekMax() {
        return maxStack.top();
    }
    
    int popMax() {
        int max = maxStack.top();
        stack<int> buffer;
        while(top() != max){
            buffer.push(pop());
        }
        pop();
        while(!buffer.empty()){
            push(buffer.top());
            buffer.pop();
        }
        return max;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
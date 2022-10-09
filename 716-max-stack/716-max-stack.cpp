class MaxStack {
    set<pair<int,int>> stack;
    set<pair<int,int>> values;
    int count;
public:
    MaxStack() {
        this->count = 0;
    }
    
    void push(int x) {
        stack.insert({count,x});
        values.insert({x,count});
        count++;
    }
    
    int pop() {
        auto temp = *stack.rbegin();
        values.erase({temp.second,temp.first});
        stack.erase(temp);
        return temp.second;
    }
    
    int top() {
        return stack.rbegin()->second;
    }
    
    int peekMax() {
        return values.rbegin()->first;
    }
    
    int popMax() {
        auto temp = *values.rbegin();
        stack.erase({temp.second,temp.first});
        values.erase(temp);
        return temp.first;
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
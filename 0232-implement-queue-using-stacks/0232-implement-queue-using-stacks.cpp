class MyQueue {
public:
    stack<int> main;
    stack<int> remain;
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        while(!main.empty()){
            remain.push(main.top());
            main.pop();
        }
        int result = remain.top();
        remain.pop();
        while(!remain.empty()){
            main.push(remain.top());
            remain.pop();
        }
        return result;
    }
    
    int peek() {
        while(!main.empty()){
            remain.push(main.top());
            main.pop();
        }
        int result = remain.top();
        while(!remain.empty()){
            main.push(remain.top());
            remain.pop();
        }
        return result;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
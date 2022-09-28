class MyCircularQueue {
public:
    vector<int> cq;
    int back = 0,maxSize = 0,front = 0;
    int currSize = 0;
    MyCircularQueue(int k) {
        cq.resize(k);
        this->maxSize = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        currSize++;
        cq[back++ % maxSize] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        currSize--;
        front++;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return cq[(front)%maxSize];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return back == 0 ? 0:cq[(back-1)%maxSize];
    }
    
    bool isEmpty() {
        if(currSize == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(currSize == maxSize) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
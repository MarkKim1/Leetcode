class LRUCache {
public:
    class node {
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int key, int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    unordered_map<int,node*>map;
    int capacity;
    node* head = new node(0,0);
    node* tail = new node(0,0);
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    void insert(node* currnode){
        currnode->next = head->next;
        head->next->prev = currnode;
        head->next = currnode;
        currnode->prev = head;
        map[currnode->key] = currnode;
    }
    
    void remove(node* currnode){
        map.erase(currnode->key);
        currnode->next->prev = currnode->prev;
        currnode->prev->next = currnode->next;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        node* currnode = map[key];
        remove(currnode);
        insert(currnode);
        return currnode->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            remove(map[key]);
        }
        if(map.size() == capacity){
            remove(tail->prev);
        }
        insert(new node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> map;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        l.splice(l.begin(),l,map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            l.splice(l.begin(),l,map[key]);
            map[key]->second = value;
            return;
        }
        if(l.size() == size){
            auto last = l.back().first;
            l.pop_back();
            map.erase(last);
        }
        l.push_front(make_pair(key,value));
        map[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
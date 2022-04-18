#define MAX_LEN 100000

class MyHashMap {
private:
    vector<pair<int,int>> map[MAX_LEN];
    
    int getIndex(int key){
        return key%MAX_LEN;
    }
    int getPos(int index, int key){
        for(int i = 0; i < map[index].size(); i++){
            if(map[index][i].first == key){
                return i;
            }
        }
        return -1;
    }
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        int pos = getPos(index,key);
        if(pos == -1){
            map[index].push_back(make_pair(key,value));
        }
        else{
            map[index][pos].second = value;
        }
    }
    
    int get(int key) {
        int index = getIndex(key);
        int pos = getPos(index,key);
        if(pos >= 0){
            return map[index][pos].second;
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int pos = getPos(index, key);
        if(pos >= 0){
            map[index].erase(map[index].begin() + pos);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
#define MAX_LEN 100000 // the amount of buckets
class MyHashSet {
    private:
    vector<int> set[MAX_LEN]; // hash set implemted by array
    
    /** Returns the corresponding bucket index */
    int getIndex(int key){
        return key % MAX_LEN;
    }
    //Search the key in a specific bucket. Returns -1 if the key does not existed
    int getPos(int key, int index){
        //Each Bucket contains a list. Iterate all the elements in the              bucket to find the target
        for(int i = 0; i <set[index].size(); i++){
            if(set[index][i] == key){
                return i;
            }
        }
        return -1;
    }
    public:
        //Initialize your data structure here
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if(pos == -1){
            set[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if(pos != -1){
            set[index].erase(set[index].begin() + pos);
        }
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        return pos >= 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
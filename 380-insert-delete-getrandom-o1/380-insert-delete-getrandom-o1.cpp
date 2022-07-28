class RandomizedSet {
    private:
    vector<int> vec;
    unordered_map<int,int> map;
    
    public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end()){
            return false;
        }
        vec.push_back(val);
        map[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) != map.end()){
            int toRemove = vec[map[val]];
            vec[map[val]] = vec.back();
            map[vec.back()] = map[val];
            vec.pop_back();
            map.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
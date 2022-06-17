class Trie {
    private:
    vector<string> a;
    public:
    Trie() {
        
    }
    
    void insert(string word) {
        a.push_back(word);
    }
    
    bool search(string word) {
        for(int i = 0; i < a.size(); i++){
            if(a[i] == word){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int count = 0;
        for(int i = 0; i < a.size(); i++){
            while(a[i][count] == prefix[count]){
                count++;
                if(count == prefix.size()){
                    return true;
                }
            }
            count = 0;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
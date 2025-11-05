class WordDictionary {
    vector<WordDictionary*> children;
    bool isLeaf;
public:
    WordDictionary(): isLeaf(false) {
        children = vector<WordDictionary*>(26,nullptr);
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr)
                curr->children[c - 'a'] = new WordDictionary();
            curr = curr->children[c - 'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        WordDictionary* curr = this;
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto ch : curr->children){
                    if(ch and ch->search(word.substr(i + 1))) return true;
                }
                return false;
            }
            if(curr->children[c - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr and curr->isLeaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
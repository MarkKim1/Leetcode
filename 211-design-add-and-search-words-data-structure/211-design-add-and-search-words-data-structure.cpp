class TrieNode{
    public: 
    
    bool isEnd;
    TrieNode* children[26];
    TrieNode(): isEnd(false){
        memset(children,0,sizeof(children));
    }
};
class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->children[word[i]-'a']){
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return search(word.c_str(),root);
    }
    bool search(const char* word,TrieNode* root){
        TrieNode* node = root;
        for(int i = 0; word[i] and node; i++){
            if(word[i] == '.'){
                TrieNode* temp = node;
                for(int j = 0; j < 26; j++){
                    node = temp->children[j];
                    if(search(word + i + 1,node)){
                        return true;
                    }
                }
            }else{
                node = node->children[word[i]-'a'];
            }
        }
        return node and node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
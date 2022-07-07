class TrieNode{
public:
    bool is_word;
    TrieNode* children[26];
    TrieNode() {
        this->is_word = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
    }
};
class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        int size = word.size();
        TrieNode* curr = root;
        int k = 0;
        for(int i = 0; i < size; i++){
            k = word[i] - 'a';
            if(curr->children[k] == NULL){
                curr->children[k] = new TrieNode();
            }
            curr = curr->children[k];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        int size = word.size();
        TrieNode* curr = root;
        int k = 0;
        for(int i = 0; i < size; i++){
            k = word[i] - 'a';
            curr = curr->children[k];
            if(curr == NULL){
                return false;
            }
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        int size = prefix.size();
        TrieNode* curr = root;
        int k = 0;
        for(int i = 0; i < size; i++){
            k = prefix[i]-'a';
            curr = curr->children[k];
            if(curr == NULL){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
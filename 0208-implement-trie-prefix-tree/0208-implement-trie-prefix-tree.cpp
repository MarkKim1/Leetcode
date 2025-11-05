class TrieNode {
    public:
    bool isLeaf;
    TrieNode* children[26];
    TrieNode() {
        isLeaf = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->children[word[i] - 'a'] == nullptr){
                TrieNode *node = new TrieNode();
                curr->children[word[i] - 'a'] = node;
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(curr->children[c - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[c - 'a'];
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
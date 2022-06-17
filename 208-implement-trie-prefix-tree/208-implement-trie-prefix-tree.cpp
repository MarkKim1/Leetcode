class TrieNode {
    public:
        map<char,TrieNode*> next;
        bool end = false;
};
class Trie {
public:
    TrieNode* node;
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* root = node;
        for(auto ch:word) {
            if(root->next.count(ch)) {
                root = root->next[ch];
            } else {
                root->next[ch] = new TrieNode();
                root = root->next[ch];
            }
            
        }
        
        root->end = true;     
        
    }
    
    bool search(string word) {
        TrieNode* root = node;
        for(auto ch:word) {
            if(root->next.count(ch)) {
                root = root->next[ch];
            }  else {
                return false;
            }
        }
        return root->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* root = node;
        for(auto ch:prefix) {
            if(root->next.count(ch)) {
                root = root->next[ch];
            }  else {
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
class TrieNode {
    public:
    vector<TrieNode*> children;
    string word;
    
    TrieNode() {
        children = vector<TrieNode*>(26,nullptr);
        word = "";
    }
    void insert(string word){
        TrieNode* curr = this;
        for(int i = 0; i < word.size(); i++){
            if(curr->children[word[i] - 'a'] == nullptr){
                curr->children[word[i]-'a'] = new TrieNode();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->word = word;
    }
};

class Solution {
public:
    vector<string> result;
    TrieNode* trie;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            trie->insert(words[i]);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                dfs(board,trie,i,j);
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& board, TrieNode* trie, int i, int j){
        if(min(i,j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') return;
        char c = board[i][j];
        if(!trie->children[c-'a']) return;
        trie = trie->children[c-'a'];
        if(trie->word.size() > 0){
            result.push_back(trie->word);
            trie->word = "";
        }
        board[i][j] = '#';
        dfs(board,trie,i + 1, j);
        dfs(board,trie,i - 1, j);
        dfs(board,trie,i, j + 1);
        dfs(board,trie,i, j - 1);
        board[i][j] = c;
    }
};
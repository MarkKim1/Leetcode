class TrieNode {
    public:
    string word = "";
    vector<TrieNode*> children;
    TrieNode() {
        for(int i = 0; i < 26; i++){
            children.push_back(NULL);
        }
    }
    
};

class Solution {
public:
    vector<string> result;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(auto word : words){
            auto temp = trie;
            for(int i = 0; i < word.size(); i++){
                if(temp->children[word[i]-'a'] == NULL){
                    temp->children[word[i]-'a'] = new TrieNode();
                }
                temp = temp->children[word[i]-'a'];
            }
            temp->word = word;
        }
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                DFS(board,trie,i,j);
            }
        }
        return result;
    }
    void DFS(vector<vector<char>>& board, TrieNode* trie, int i, int j){
        if(min(i,j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#'){
            return;
        }
        if(!trie->children[board[i][j]-'a']){
            return;
        }
        trie = trie->children[board[i][j]-'a'];
        if(trie->word.size() > 0){
            string curr = trie->word;
            result.push_back(curr);
            trie->word = "";
        }
        char c = board[i][j];
        board[i][j] = '#';
        DFS(board,trie,i+1,j);
        DFS(board,trie,i,j+1);
        DFS(board,trie,i,j-1);
        DFS(board,trie,i-1,j);
        board[i][j] = c;
    }
};
class TrieNode {
    public:
    string word = "";
    vector<TrieNode*> children;
    TrieNode(){
        children.resize(26);
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};
class Solution {
public:
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        
        for(auto word: words){
            auto temp = trie;
            for(int i = 0; i < word.size(); i++){
                if(temp->children[word[i]-'a'] == NULL){
                    temp->children[word[i]-'a'] = new TrieNode();
                }
                temp = temp->children[word[i]-'a'];
            }
            temp->word = word;
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                backtrack(board,trie,i,j);
            }
        }
        return ans;
    }
    void backtrack(vector<vector<char>>& board, TrieNode* trie, int i, int j){
        if(min(i,j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#'){
            return;
        }
        if(!trie->children[board[i][j]-'a']){
            return;
        }
        trie = trie->children[board[i][j]-'a'];
        if(trie->word.size() > 0){
            ans.push_back(trie->word);
            trie->word = "";
        }
        char c = board[i][j];
        board[i][j] = '#';
        backtrack(board,trie,i+1,j);
        backtrack(board,trie,i,j+1);
        backtrack(board,trie,i-1,j);
        backtrack(board,trie,i,j-1);
        board[i][j] = c;
    }
};
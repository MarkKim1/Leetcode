class TrieNode {
    public:
    string word = "";
    vector<TrieNode*> children;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children.push_back(nullptr);
        }
    }
};
class Solution {
public:
    vector<string> result;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        
        for(auto word: words){
            TrieNode* temp = trie;
            for(int i = 0; i < word.size(); i++){
                if(temp->children[word[i]-'a'] == NULL){
                    temp->children[word[i]-'a'] = new TrieNode();
                }
                temp = temp->children[word[i]-'a'];
            }
            temp->word = word;
        }
        //traverse board
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                DFS(board,trie,i,j);
            }
        }
        return result;
    }
    void DFS(vector<vector<char>>& board, TrieNode* trie, int i, int j){
        if(min(i,j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#'){
            return;
        }
        char c = board[i][j];
        if(!trie->children[c-'a']){
            return;
        }
        trie = trie->children[c-'a'];
        if(trie->word.size() > 0){
            result.push_back(trie->word);
            trie->word = "";
        } 
        
        board[i][j] = '#';
        DFS(board,trie,i+1,j);
        DFS(board,trie,i-1,j);
        DFS(board,trie,i,j+1);
        DFS(board,trie,i,j-1);
        board[i][j] = c;
        
    }
};
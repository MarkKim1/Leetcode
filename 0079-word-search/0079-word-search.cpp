class Solution {
public:
    bool res = false;
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    dfs(board,i,j,word);
                    if(res) return true;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, int i, int j, string word){
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == '#' or board[i][j] != word[0]){
            return;
        }
        if(word.size() == 1 and board[i][j] == word[0]){
            res = true;
        }
        char c = board[i][j];
        board[i][j] = '#';
        dfs(board,i + 1,j,word.substr(1));
        dfs(board,i - 1,j,word.substr(1));
        dfs(board,i,j + 1, word.substr(1));
        dfs(board,i,j - 1, word.substr(1));
        board[i][j] = c;
    }
};
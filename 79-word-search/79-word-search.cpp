class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[index])
                    if(dfs(i,j,board,word,index))return true;
            }
        }
        return false;
    }
    bool dfs(int i, int j, vector<vector<char>> &board, string word,int index){
        if(index == word.size()){
            return true;
        }
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }
        board[i][j] = '#';
        if(dfs(i+1,j,board,word,index+1) ||
           dfs(i,j+1,board,word,index+1) ||
           dfs(i-1,j,board,word,index+1) ||
           dfs(i,j-1,board,word,index+1)){
            return true;
        }
        board[i][j] = word[index];
        return false;
    }
};
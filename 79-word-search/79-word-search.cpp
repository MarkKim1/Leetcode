class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(DFS(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool DFS(int i, int j, vector<vector<char>>& board, string word,int count){
        if(count == word.size()) return true;
        if(min(i,j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[count]){
            return false;
        }
        char a = board[i][j];
        board[i][j] = '%';
        bool ret = DFS(i+1,j,board,word,count+1) || DFS(i,j+1,board,word,count+1) || DFS(i-1,j,board,word,count+1) || DFS(i,j-1,board,word,count+1);
        board[i][j] = a;
        return ret;
    }
};
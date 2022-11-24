class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(helper(0,i,j,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool helper(int index, int i, int j,vector<vector<char>>& board, string word){
        if(index >= word.size()){
            return true;
        }
        if(min(i,j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }
        char original = board[i][j];
        board[i][j] = '#';
        bool a = helper(index+1,i+1,j,board,word);
        bool b = helper(index+1,i-1,j,board,word);
        bool c = helper(index+1,i,j+1,board,word);
        bool d = helper(index+1,i,j-1,board,word);
        board[i][j] = original;
        return a || b || c || d;
    }
};
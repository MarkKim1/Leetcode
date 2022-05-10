class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowSize = board[0].size()-1;
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O'){
                DFS(i,0,board);
            }
            if(board[i][rowSize] == 'O'){
                DFS(i,rowSize,board);
            }
        }
        
        int colSize = board.size()-1;
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O'){
                DFS(0,i,board);
            }
            if(board[colSize][i] == 'O'){
                DFS(colSize,i,board);
            }
        }
        
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j] == '#'){
                        board[i][j] = 'O';
                    }else{
                        board[i][j] = 'X';
                    }
            }
        }
    }
    void DFS(int i, int j, vector<vector<char>>& board){
        if(i>=0 && j >=0 && i <=board.size()-1 && j <= board[0].size()-1 && board[i][j] == 'O'){
        board[i][j] = '#';
        DFS(i+1,j,board);
        DFS(i-1,j,board);
        DFS(i,j+1,board);
        DFS(i,j-1,board);
        }
    }
};
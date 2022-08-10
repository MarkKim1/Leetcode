class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result(board.size(),vector<int>(board[0].size(),0));
        vector<int> x = {-1,-1,-1,0,0,1,1,1};
        vector<int> y = {-1,0,1,-1,1,-1,0,1};
        
        int row = board.size();
        int col = board[0].size();
        int live_count = 0;
        int dead_count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 0){
                    for(int k = 0; k < x.size(); k++){
                        int neighbor_x = x[k];
                        int neighbor_y = y[k];
                        if(i + neighbor_x >= 0 and j + neighbor_y >= 0 and i + neighbor_x < row and j + neighbor_y < col){
                            if(board[i + neighbor_x][j + neighbor_y] == 1){
                                live_count++;
                            }
                        }
                    }
                    if(live_count == 3){
                        result[i][j] = 1;
                    }
                    live_count = 0;
                }else if(board[i][j] == 1){
                    for(int k = 0; k < x.size(); k++){
                        int neighbor_x = x[k];
                        int neighbor_y = y[k];
                        if(i + neighbor_x >= 0 and j + neighbor_y >= 0 and i + neighbor_x < row and j + neighbor_y < col){
                            if(board[i + neighbor_x][j + neighbor_y] == 0){
                                dead_count++;
                            }else{
                                live_count++;
                            }
                        }
                    }
                    if(live_count < 2){
                        result[i][j] = 0;
                    }else if(live_count <= 3){
                        result[i][j] = 1;
                    }else if(dead_count > 3){
                        result[i][j] = 0;
                    }
                    dead_count = 0;
                    live_count = 0;
                }
            }
        }
        board = result;
    }
};
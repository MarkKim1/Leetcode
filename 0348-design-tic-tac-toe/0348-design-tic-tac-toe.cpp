class TicTacToe {
public:
    vector<int> row1,col1,row2,col2;
    int dig1 = 0,anti1 = 0,dig2 = 0,anti2 = 0;
    int n;
    TicTacToe(int n) {
        row1.resize(n,0);
        row2.resize(n,0);
        col1.resize(n,0);
        col2.resize(n,0);
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        if(player == 1){
            row1[row]++;
            col1[col]++;
            if(row == col){
                dig1++;
            }
            if(row + col == n-1){
                anti1++;
            }
            if(row1[row] == n || col1[col] == n || dig1 == n || anti1 == n){
                return player;
            }
        }else{
            row2[row]++;
            col2[col]++;
            if(row == col){
                dig2++;
            }
            if(row + col == n-1){
                anti2++;
            }
            if(row2[row] == n || col2[col] == n || dig2 == n || anti2 == n){
                return player;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
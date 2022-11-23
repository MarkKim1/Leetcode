class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> row;
        unordered_map<int,unordered_set<int>> col;
        unordered_map<int,unordered_set<int>> box;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(isdigit(board[i][j])){
                    if(row[i].count(board[i][j]-'0')){
                        return false;
                    }
                    if(col[j].count(board[i][j]-'0')){
                        return false;
                    }
                    int box_index = ((i/3)*3) - (j/3);
                    if(box[box_index].count(board[i][j]-'0')){
                        return false;
                    }
                    row[i].insert(board[i][j]-'0');
                    col[j].insert(board[i][j]-'0');
                    box[box_index].insert(board[i][j]-'0');
                }
            }
        }
        return true;
    }
};
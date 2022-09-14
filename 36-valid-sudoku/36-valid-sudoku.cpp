class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> col_map;
        unordered_set<char> row_set; 
        unordered_map<int,unordered_set<char>> box_map;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                if(row_set.count(board[i][j])){
                    return false;
                }
                row_set.insert(board[i][j]);
                if(col_map[j].count(board[i][j])){
                    return false;
                }
                col_map[j].insert(board[i][j]);
                int index = (i/3) * 3 + j/3;
                if(box_map[index].count(board[i][j])){
                    return false;
                }
                box_map[index].insert(board[i][j]);
            }
            row_set.clear();
        }
        return true;
    }
};

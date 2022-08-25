class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,vector<int>> rows;
        unordered_map<int,vector<int>> cols;
        unordered_map<int,vector<int>> box;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(find(rows[i].begin(),rows[i].end(),board[i][j]-'0') != rows[i].end()){
                    return false;
                }
                rows[i].push_back(board[i][j]-'0');
                if(find(cols[j].begin(),cols[j].end(),board[i][j]-'0') != cols[j].end()){
                    return false;
                }
                cols[j].push_back(board[i][j]-'0');
                int k = (i / 3) * 3 + j/3;
                if(find(box[k].begin(),box[k].end(),board[i][j]-'0') != box[k].end()){
                    return false;
                }
                box[k].push_back(board[i][j]-'0');
            }
        }
        return true;
    }
};
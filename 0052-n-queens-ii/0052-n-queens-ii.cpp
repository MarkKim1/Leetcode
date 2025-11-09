class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> bottomRightDiag;
    unordered_set<int> bottomLeftDiag;
    int res = 0;
    int totalNQueens(int n) {
        backtrack(0,n);
        return res;
    }
    void backtrack(int row, int n){
        if(row == n){
            res++;
            return;
        }
        for(int col = 0; col < n; col++){
            if(cols.count(col) || bottomRightDiag.count(row - col) || bottomLeftDiag.count(row + col)){
                continue;
            }
            cols.insert(col);
            bottomRightDiag.insert(row - col);
            bottomLeftDiag.insert(row + col);
            backtrack(row + 1, n);
            cols.erase(col);
            bottomRightDiag.erase(row - col);
            bottomLeftDiag.erase(row + col);
        }
    }
};
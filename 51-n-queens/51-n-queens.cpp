class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> negDiag;
    unordered_set<int> posDiag;
    vector<vector<string>> ans;
    vector<string> sub;
    vector<vector<string>> solveNQueens(int n) {
        string dot = "";
        for(int i = 0; i < n; i++){
            dot.push_back('.');
        }
        for(int i = 0; i < n; i++){
            sub.push_back(dot);
        }
        backtrack(0,n);
        return ans;
    }
    void backtrack(int r,int n){
        if(r == n){
            ans.push_back(sub);
            return;
        }
        for(int c = 0; c < n; c++){
            if(cols.count(c) || negDiag.count(r-c) || posDiag.count(r+c)){
                continue;
            }
            cols.insert(c);
            negDiag.insert(r-c);
            posDiag.insert(r+c);
            sub[r][c] = 'Q';
            backtrack(r+1,n);
            sub[r][c] = '.';
            cols.erase(c);
            negDiag.erase(r-c);
            posDiag.erase(r+c);
        }
    }
};
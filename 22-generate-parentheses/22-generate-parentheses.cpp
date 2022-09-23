class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0, close = 0;
        string result = "";
        backtracking(n,ans,open,close,result);
        return ans;
    }
    void backtracking(int n, vector<string>& ans,int open, int close, string result){
        if(close == n){
            ans.push_back(result);
        }
        if(open < n){
            result.push_back('(');
            backtracking(n,ans,open+1,close,result);
            result.pop_back();
        }
        if(close < open){
            result.push_back(')');
            backtracking(n,ans,open,close+1,result);
            result.pop_back();
        }
    }
};
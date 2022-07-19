class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string parenthesis;
        //parenthesis.resize(2*n);
        generate(parenthesis,0,0,n);
        return result;
    }
    void generate(string parenthesis,int open, int close, int max){
        if(parenthesis.size() == max*2){
            result.push_back(parenthesis);
            return;
        }
        if(open < max){
            parenthesis.push_back('(');
            generate(parenthesis,open+1,close,max);
            parenthesis.pop_back();
        }
        if(close < open){
            parenthesis.push_back(')');
            generate(parenthesis,open,close+1,max);
            parenthesis.pop_back();   
        }
    }
};
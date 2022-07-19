class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string parenthesis;
        //parenthesis.resize(2*n);
        generate(parenthesis,2*n);
        return result;
    }
    void generate(string parenthesis,int valid){
        if(valid == 0){
            if(isvalid(parenthesis)){
                result.push_back(parenthesis);
            }
            return;
        }
        parenthesis.push_back('(');
        generate(parenthesis,valid-1);
        parenthesis.pop_back();
        
        parenthesis.push_back(')');
        generate(parenthesis,valid-1);
        parenthesis.pop_back();
    }
    bool isvalid(string parenthesis){
        int balance = 0;
        for(int i = 0; i < parenthesis.size(); i++){
            if(parenthesis[i] == '('){
                balance++;
            }
            if(parenthesis[i] == ')'){
                balance--;
            }
            if(balance < 0) return false;
        }
        return balance == 0 ? true : false;
    }
};
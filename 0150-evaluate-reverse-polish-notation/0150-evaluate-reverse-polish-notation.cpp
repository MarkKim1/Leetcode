class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" and tokens[i] != "-" and tokens[i] != "/" and tokens[i] != "*"){
                int num = stoi(tokens[i]);
                stk.push(num);
            }
            else{
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                if(tokens[i] == "+"){
                    stk.push(first + second);
                }
                else if(tokens[i] == "-"){
                    stk.push(first - second);
                }
                else if(tokens[i] == "*"){
                    stk.push(first * second);
                }
                else{
                    stk.push(first / second);
                }
            }
        }
        return stk.top();
    }
};
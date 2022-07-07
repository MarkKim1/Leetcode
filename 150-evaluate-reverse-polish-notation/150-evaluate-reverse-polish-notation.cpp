class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int first;
        int second;
        int number = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                first = stk.top();
                stk.pop();
                second = stk.top();
                stk.pop();
                int result = second + first;
                stk.push(result);
                
            }
            else if(tokens[i] == "-"){
                first = stk.top();
                stk.pop();
                second = stk.top();
                stk.pop();
                int result = second - first;
                stk.push(result);
            }
            else if(tokens[i] == "*"){
                first = stk.top();
                stk.pop();
                second = stk.top();
                stk.pop();
                int result = second * first;
                stk.push(result);
            }
            else if(tokens[i] == "/"){
                first = stk.top();
                stk.pop();
                second = stk.top();
                stk.pop();
                int result = second / first;
                stk.push(result);
            }
            else{
                number = stoi(tokens[i]);
                stk.push(number);
            }
        }
        return stk.top();
    }
};
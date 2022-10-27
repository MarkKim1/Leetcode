class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        int curr = 0;
        bool neg = false;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" and tokens[i] != "-" and tokens[i] != "/" and tokens[i] != "*"){    
                for(int j = 0; j < tokens[i].size(); j++){
                    if(tokens[i][j] == '-'){
                        neg = true;
                    }else{
                        curr = curr * 10 + (tokens[i][j]-'0');
                    }
                }
                if(neg) curr = -curr;
                stk.push(curr);
                curr = 0;
                neg = false;
            }else{
                long long second = stk.top();
                stk.pop();
                long long first = stk.top();
                stk.pop();
                if(tokens[i] == "+"){
                    stk.push(first + second);
                }
                if(tokens[i] == "-"){
                    stk.push(first-second);
                }
                if(tokens[i] == "/"){
                    stk.push(first/second);
                }
                if(tokens[i] == "*"){
                    stk.push(first*second);
                }
            }
            
        }
        return stk.top();
    }
};
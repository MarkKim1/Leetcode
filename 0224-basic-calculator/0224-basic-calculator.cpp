class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int result = 0;
        long long curr_number = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                curr_number = curr_number * 10 + s[i]-'0';
            }else if(s[i] == '-'){
                result += sign * curr_number;
                curr_number = 0;
                sign = -1;
            }else if(s[i] == '+'){
                result += sign * curr_number;
                curr_number = 0;
                sign = 1;
            }else if(s[i] == '('){
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            }else if(s[i] == ')'){
                result+=sign*curr_number;
                result*=stk.top();
                stk.pop();
                result+=stk.top();
                stk.pop();
                curr_number = 0;
                sign = 1;
            }
        }
        if(curr_number != 0){
            result += sign * curr_number;
        }
        return result;
    }
};
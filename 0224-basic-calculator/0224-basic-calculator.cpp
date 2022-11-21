class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        long long number = 0;
        int sign = 1;
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                number = 10 * number + s[i] - '0';
            }else if(s[i] == '-'){
                result += sign * number;
                number = 0;
                sign = -1;
            }else if(s[i] == '+'){
                result += sign * number;
                number = 0;
                sign = 1;
            }else if(s[i] == '('){
                stack.push(result);
                stack.push(sign);
                result = 0;
                sign = 1;
            }else if(s[i] == ')'){
                result += sign * number;
                result *= stack.top();
                stack.pop();
                result += stack.top();
                stack.pop();
                number = 0;
            }
        }
        if(number != 0){
            result += (sign == -1) ? -number : number;
        }
        return result;
    }
};
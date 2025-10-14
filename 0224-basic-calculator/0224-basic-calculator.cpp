class Solution {
public:
    int calculate(string s) {
        stack<long long> stk;
        long long sign = 1;
        long long num = 0;
        long long result = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                num = (num * 10) + (s[i] - '0');
            }else{
                result += sign * num;
                num = 0;
                if(s[i] == '+'){
                    sign = 1; 
                }
                if(s[i] == '-'){
                    sign = -1;
                }
                if(s[i] == '('){
                    stk.push(result);
                    stk.push(sign);
                    result = 0;
                    sign = 1;
                }
                if(s[i] == ')'){
                    long long prevSign = stk.top(); stk.pop();
                    long long prevResult = stk.top(); stk.pop();
                    result = prevSign * result + prevResult;
                }
            }
        }
        result += sign * num;
        return (int)result;
    }
};
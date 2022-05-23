class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int len = s.length();
        int currentNumber = 0;
        char operation = '+';
        for(int i = 0; i < len; i++){
            char currentChar = s[i];
            if(isdigit(currentChar)){
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if(!isdigit(currentChar) and !iswspace(currentChar) || i == len-1){
                if(operation == '+'){
                    stack.push(currentNumber);
                }else if(operation == '-'){
                    stack.push(-currentNumber);
                }else if(operation == '*'){
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                }else if(operation == '/'){
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
            while(!stack.empty()){
                result+=stack.top();
                stack.pop();
            }
        return result;
    }
};
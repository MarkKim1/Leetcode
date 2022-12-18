class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,function<long long(long long, long long)>> map = {
            {"+",[](long long a, long long b){return a+b;}},
            {"-",[](long long a, long long b){return a-b;}},
            {"*",[](long long a, long long b){return a*b;}},
            {"/",[](long long a, long long b){return a/b;}}
        };
        stack<long long> stack;
        for(int i = 0; i < tokens.size(); i++){
            string temp = tokens[i];
            if(temp != "-" and temp != "+" and temp != "*" and temp != "/"){
                stack.push(stoll(temp));
            }else{
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(map[temp](b,a));
            }
        }
        return (int)stack.top();
    }
};
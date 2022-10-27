class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,function<long long (long long,long long) > >map = {
            {"+",[](long long a, long long b) {return a+b;}},
            {"*",[](long long a, long long b) {return a*b;}},
            {"/",[](long long a, long long b) {return a/b;}},
            {"-",[](long long a, long long b) {return a-b;}}
        };
        stack<long long> stk;
        
        for(auto s : tokens){
            if(map.find(s) == map.end()){
                stk.push(stoi(s));
            }else{
                long long second = stk.top();
                stk.pop();
                long long first = stk.top();
                stk.pop();
                stk.push(map[s](first,second));
            }
        }
        return stk.top();
    }
};
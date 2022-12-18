class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        vector<int> result(temp.size(),0);
        for(int i = 0; i < temp.size(); i++){
            if(stk.empty()){
                stk.push(i);
            }else{
                while(!stk.empty() and temp[stk.top()] < temp[i]){
                    result[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return result;
    }
};
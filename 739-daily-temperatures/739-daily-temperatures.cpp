class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> stack;
        vector<int> result(temp.size());
        for(int i = 0; i < temp.size(); i++){
            if(stack.empty()){
                stack.push({i,temp[i]});
                continue;
            }
            while(!stack.empty() and temp[i] > stack.top().second){
                result[stack.top().first] = i-stack.top().first;
                stack.pop();
            }
            stack.push({i,temp[i]});
        }
        return result;
    }
};
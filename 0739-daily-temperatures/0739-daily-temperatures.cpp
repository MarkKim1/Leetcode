class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> stk;
        vector<int> ans(temp.size());
        for(int i = 0; i < temp.size(); i++){
            if(stk.empty()){
                stk.push({i,temp[i]});
                continue;
            }
            while(!stk.empty() and temp[i] > stk.top().second){
                ans[stk.top().first] = i-stk.top().first;
                stk.pop();
            }
            stk.push({i,temp[i]});
        }
        return ans;
    }
};
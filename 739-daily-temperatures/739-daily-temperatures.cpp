class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(),0);
        stack<pair<int,int>> stk;
        int temp = temperatures[0];
        stk.push(make_pair(temp,0));
        int i = 1;
        for(int i = 0; i < temperatures.size(); i++){
            if(temperatures[i] > stk.top().first){
                while(!stk.empty() and stk.top().first < temperatures[i]){
                    answer[stk.top().second] = i-stk.top().second;
                    stk.pop();
                }
            }
            stk.push(make_pair(temperatures[i],i));
        }
        return answer;
    }
};
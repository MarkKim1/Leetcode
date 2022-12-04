class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            while(stk.top() != -1 and heights[stk.top()] >= heights[i]){
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i-stk.top()-1;
                ans = max(ans,current_height * current_width);
            }
            stk.push(i);
        }
        while(stk.top() != -1){
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size()-stk.top()-1;
            ans = max(ans,current_height * current_width);
        }
        return ans;
    }
};
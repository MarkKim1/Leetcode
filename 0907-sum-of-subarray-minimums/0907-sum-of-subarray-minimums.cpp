class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        int MOD = 1000000007;
        long ans = 0;
        for(int i = 0; i <= arr.size(); i++){
            
            while(!stk.empty() and (i == arr.size() || arr[stk.top()] >= arr[i])){
                int mid = stk.top();
                stk.pop();
                int left_boundary = stk.empty() ? -1 : stk.top();
                int right_boundary = i;
                long contribution = (mid - left_boundary) * (right_boundary-mid);
                ans += (arr[mid] * contribution);
                ans %= MOD;
            }
            stk.push(i);
        }
        return int(ans);
    }
};
//334
// 3 => i = 0
// mid = 4
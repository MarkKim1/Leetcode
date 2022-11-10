class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<>> left;
        priority_queue<int,vector<int>,greater<>> right;
        int i = 0;
        int j = costs.size()-1;
        long long ans = 0;
        while(k--){
            while(left.size() < candidates and i <= j) left.push(costs[i++]);
            while(right.size() < candidates and i <= j) right.push(costs[j--]);
            int a = left.size() > 0 ? left.top() : INT_MAX;
            int b = right.size() > 0 ? right.top() : INT_MAX;
            if(a <= b){
                ans+=a;
                left.pop();
            }else{
                ans+=b;
                right.pop();
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for(int i = n-2; ~i; i--){
            costs[i][0] = min(costs[i+1][1],costs[i+1][2]) + costs[i][0];
            costs[i][1] = min(costs[i+1][0],costs[i+1][2]) + costs[i][1];
            costs[i][2] = min(costs[i+1][0],costs[i+1][1]) + costs[i][2];
        }
        return min(costs[0][0],min(costs[0][1],costs[0][2]));
    }
};
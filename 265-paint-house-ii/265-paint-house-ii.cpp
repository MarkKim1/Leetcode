class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int ROW = costs.size();
        int COL = costs[0].size();
        int k = INT_MAX;
        for(int i = 1; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                for(int n = 0; n < COL; n++){
                    if(n == j){
                        continue;
                    }
                    k = min(k,costs[i-1][n]);
                }
                costs[i][j] +=k;
                k = INT_MAX;
            }
        }
        int result = INT_MAX;
        for(int i = 0; i < COL; i++){
            result = min(costs[ROW-1][i],result);
        }
        return result;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> temp(prices);
            for(auto f : flights){
                if(prices[f[0]] == INT_MAX){
                    continue;
                }
                if(prices[f[0]] + f[2] < temp[f[1]]){
                    temp[f[1]] = prices[f[0]] + f[2];
                }
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
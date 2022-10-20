class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>prices(n,INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int>temp(prices);
            for(auto flight: flights){
                if(prices[flight[0]] == INT_MAX){
                    continue;
                }
                if(prices[flight[0]] + flight[2] < temp[flight[1]]){
                    temp[flight[1]] = prices[flight[0]] + flight[2];
                }
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
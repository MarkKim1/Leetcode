class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        
        for(int i = 0; i <= k; i++){
            vector<int> temp(prices);
            for(int j = 0; j < flights.size(); j++){
                if(prices[flights[j][0]] == INT_MAX){
                    continue;
                }
                if(prices[flights[j][0]] + flights[j][2] < temp[flights[j][1]]){
                    temp[flights[j][1]] = prices[flights[j][0]] + flights[j][2];
                }
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
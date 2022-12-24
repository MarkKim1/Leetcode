class Solution {
public:
    vector<vector<int>> cache;
    int maxProfit(vector<int>& prices) {
        cache.resize(prices.size(),vector<int>(2,-1));
        int buying = true;
        return helper(prices,0,buying);
    }
    int helper(vector<int>& prices, int index, bool buying){
        if(index >= prices.size()){
            return 0;
        }
        if(cache[index][buying] != -1){
            return cache[index][buying];
        }
        int x,y;
        if(buying){
            x = helper(prices,index + 1, !buying) - prices[index];
            y = helper(prices,index + 1, buying);
            return cache[index][buying] = max(x,y);
        }else{
            x = helper(prices,index + 2, !buying) + prices[index];
            y = helper(prices,index + 1, buying);
            return cache[index][buying] = max(x,y);
        }
    }
};
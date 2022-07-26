class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell= INT_MIN;
        for(int i = 0; i < prices.size()-1; i++){
            buy = min(buy,prices[i]);
            sell = max(sell,prices[i+1]-buy);
        }
        return sell < 0 ? 0:sell;
    }
};
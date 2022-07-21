class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxPrice = prices[0];
        int totalCount = 0;
        for(int i = 1; i < prices.size(); i++){
            if(minPrice > prices[i]){
                minPrice = prices[i];
                maxPrice = prices[i];
            }else if(prices[i] > maxPrice){
                int a = prices[i] - maxPrice;
                totalCount+=a;
                maxPrice = prices[i];
            }else{
                minPrice = prices[i];
                maxPrice = prices[i];
            }
        }
        return totalCount;
    }
};
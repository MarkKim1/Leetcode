class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = INT_MIN,result = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            result = min(result,prices[i]);
            curr = max(curr,prices[i]-result);
        }
        return curr;
    }
};
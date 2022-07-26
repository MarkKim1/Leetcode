class Solution {
public:
    unordered_map<int,unordered_map<bool,int>> map;
    int maxProfit(vector<int>& prices) {
       return dfs(0,true,prices);
    }
    int dfs(int i, bool buying,vector<int>& prices){
        if(i >= prices.size()){
            return 0;
        }
        if(map[i].find(buying) != map[i].end()){
            return map[i][buying];
        }
        if(buying){
            int buy = dfs(i+1,!buying,prices)-prices[i];
            int cooldown = dfs(i+1,buying,prices);
            map[i][buying] = max(buy,cooldown); 
        }else{
            int sell = dfs(i+2,!buying,prices) + prices[i];
            int cooldown = dfs(i+1,buying,prices);
            map[i][buying] = max(sell,cooldown); 
        }
        return map[i][buying];
    }
};
class Solution {
    int[] prices;
    int[][][] memo;
    public int maxProfit(int k, int[] prices) {
        this.prices = prices;
        this.memo = new int[prices.length][k+1][2];
        return dp(0,k,0);
    }
    
    private int dp(int i, int tR, int holding){
        if(tR == 0 || i == prices.length){
            return 0;
        }
        if(memo[i][tR][holding] == 0){
            int doNothing = dp(i+1,tR,holding);
            int doSomething;
            
            if(holding == 1){
                //sell stock
                doSomething = prices[i] + dp(i+1,tR-1,0); 
            }else{
                //buy stock
                doSomething = -prices[i] + dp(i+1,tR,1);
            }
            memo[i][tR][holding] = Math.max(doNothing,doSomething);
        }
        return memo[i][tR][holding];
    }
}
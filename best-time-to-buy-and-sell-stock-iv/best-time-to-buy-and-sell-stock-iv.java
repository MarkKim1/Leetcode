class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n+1][k+1][2];
        
        for(int i = n-1; i >= 0; i--){
            for(int transactionRemaining = 1; transactionRemaining <= k; transactionRemaining++){
                for(int holding = 0; holding < 2; holding++){
                    int doNothing = dp[i+1][transactionRemaining][holding];
                    int doSomething;
                    
                    if(holding == 1){//sell stock
                        doSomething = prices[i] + dp[i+1][transactionRemaining-1][0];
                    }else{//buy stock
                        doSomething = -prices[i] + dp[i+1][transactionRemaining][1];
                    }
                    dp[i][transactionRemaining][holding] = Math.max(doNothing,doSomething);
                }
            }
        }
        return dp[0][k][0];
    }
}
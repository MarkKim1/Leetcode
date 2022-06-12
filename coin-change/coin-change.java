class Solution {
    
    public int coinChange(int[] coins, int amount) {
        int[] count = new int[amount];
        return result(coins,amount,count);
    }
    
    public int result(int[] coins,int rem, int[] count){
        if(rem == 0) return 0;
        if(rem < 0) return -1;
        if(count[rem-1] != 0) return count[rem-1];
        
        int min = Integer.MAX_VALUE;
        
        for(int coin: coins){
            int res = result(coins,rem-coin,count);
            if(res >= 0 && res < min){
                min = res + 1;
            }
        }
        count[rem-1] = (min == Integer.MAX_VALUE) ? -1 : min;
        return count[rem-1];
    }
}
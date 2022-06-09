class Solution {
    int n,d;
    int[][]dp;
    int[] hardestRemainder;
    int[] jobDifficulty;
    public int minDifficulty(int[] jobDifficulty, int d) {
        if(jobDifficulty.length < d){
            return -1;
        }
        this.jobDifficulty = jobDifficulty;
        this.n = jobDifficulty.length;
        int hardest = 0;
        this.hardestRemainder = new int[n];
        
        for(int i = n-1; i>=0; i--){
            hardest = Math.max(jobDifficulty[i],hardest);
            hardestRemainder[i] = hardest;
        }
        
        dp = new int[n][d+1];
        this.d = d;
        
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i],-1);
        }
        return dp(0,1);
    }
    
    public int dp(int i, int day){
        if(d == day){
            return hardestRemainder[i];
        }
        
        if(dp[i][day] == -1){
            int hardest = 0;
            int answer = Integer.MAX_VALUE;
            for(int j = i; j < n-(d-day); j++){
                hardest = Math.max(hardest,jobDifficulty[j]);
                answer = Math.min(answer,hardest + dp(j+1,day+1));
            }
            dp[i][day] = answer;
        }
        return dp[i][day];
    }
}
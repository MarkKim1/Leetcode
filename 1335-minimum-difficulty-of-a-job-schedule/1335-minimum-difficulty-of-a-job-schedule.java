class Solution {
    private int n,d;
    private int[][] memo;
    private int[] jobDifficulty;
    private int[] hardestJobremaining;
    
    private int dp(int i, int day){
        //Base case, it's the last day so we need to finish all the jobs
        if(day == d){
            return hardestJobremaining[i];
        }
        
        if(memo[i][day] == -1){
            int best = Integer.MAX_VALUE;
            int hardest = 0;
            //Iterate through the options and choose the best
            for(int j = i; j<n-(d-day); j++){
                hardest = Math.max(hardest,jobDifficulty[j]);
                //Recurrence relation
                best = Math.min(best,hardest + dp(j+1,day+1));
            }
            memo[i][day] = best;
        }
        return memo[i][day];
    }
    
    public int minDifficulty(int[] jobDifficulty, int d) {
        this.n = jobDifficulty.length;
        //If we cannot schedule at least one job per day,
        //it is impossbile to create a schedule
        if(n < d) return -1;
        
        hardestJobremaining = new int[n];
        int hardestJob = 0;
        for(int i = n-1; i >= 0; i--){
            hardestJob = Math.max(hardestJob,jobDifficulty[i]);
            hardestJobremaining[i] = hardestJob;
        }
        //Intialize memo array with value of -1
        memo = new int[n][d+1];
        for(int i = 0; i < n; i++){
            Arrays.fill(memo[i],-1);
        }
        this.d = d;
        this.jobDifficulty = jobDifficulty;
        return dp(0,1);
    }
}
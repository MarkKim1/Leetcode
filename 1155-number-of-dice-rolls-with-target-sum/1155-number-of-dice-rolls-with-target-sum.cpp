class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    int numRollsToTarget(int n, int k, int target) {
        memo.resize(n+1,vector<int>(target+1,-1));
        return recursive(0,0,n,k,target);
    }
    int recursive(int curr_index, int curr_sum,int n, int k, int target){
        if(curr_index == n){
            return curr_sum == target;
        }
        if(memo[curr_index][curr_sum] != -1){
            return memo[curr_index][curr_sum];
        }
        int ans = 0;
        for(int i = 1; i <= min(k, target - curr_sum); i++){
            ans = (ans + recursive(curr_index+1,curr_sum+i,n,k,target)) % MOD;
        }
        memo[curr_index][curr_sum] = ans;
        return ans;
    }
};
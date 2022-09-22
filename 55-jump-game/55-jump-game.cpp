enum Index{
    GOOD, BAD, UNKNOWN
};
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size());
        for(int i = 0; i < memo.size(); i++){
            memo[i] = UNKNOWN;
        }
        memo[memo.size()-1] = GOOD;
        return canJumpFromPosition(0,nums,memo);
    }
    bool canJumpFromPosition(int i, vector<int>& nums,vector<Index>& memo){
        if(memo[i] != UNKNOWN){
            return memo[i] == GOOD ? true : false;
        }
        int size = nums.size()-1;
        int jump = min(i + nums[i],size);
        for(int j = i+1; j <= jump; j++){
            if(canJumpFromPosition(j,nums,memo)){
                memo[i] = GOOD;
                return true;
            }
        }
        memo[i] = BAD;
        return false;
    }
};
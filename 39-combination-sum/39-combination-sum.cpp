class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        backtrack(candidates,0,target,output,0);
        return result;
    }
    void backtrack(vector<int>& candidates, int sum, int target,vector<int>& output,int start){
        if(target == sum){
            result.push_back(output);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(sum + candidates[i] <= target){
                output.push_back(candidates[i]);
                backtrack(candidates,sum + candidates[i],target,output,i);
                output.pop_back();
            }
        }
        
    }
};
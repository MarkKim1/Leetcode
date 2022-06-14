class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        int sum = 0;
        recurs(sub,candidates,sum,target,0);
        return result;
    }
    void recurs(vector<int> sub,vector<int>& candidates,int sum,int target,int start){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(sub);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
                sub.emplace_back(candidates[i]);
                recurs(sub,candidates,sum+candidates[i],target,i);
                sub.pop_back();
        }
    }
};
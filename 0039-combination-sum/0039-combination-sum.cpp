class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0,0,{});
        return result;
    }
    void helper(vector<int>& candidates, int target, int curr, int pos, vector<int> vec){
        if(curr == target){
            result.push_back(vec);
            return;
        }
        for(int i = pos; i < candidates.size(); i++){
            if(curr + candidates[i] <= target){
                vec.push_back(candidates[i]);
                helper(candidates, target, curr + candidates[i], i, vec);
                vec.pop_back();
            }
        }
    }
};
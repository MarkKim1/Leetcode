class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> visited;
    vector<int> temp;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums);
        return result;
    }
    void helper(vector<int>& nums){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited.count(nums[i])) continue;
            temp.push_back(nums[i]);
            visited.insert(nums[i]);
            helper(nums);
            temp.pop_back();
            visited.erase(nums[i]);
        }
    }
};
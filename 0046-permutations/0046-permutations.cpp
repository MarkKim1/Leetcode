class Solution {
public:
    unordered_set<int> set;
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,{});
        return result;
    }
    void helper(vector<int>& nums, vector<int> curr){
        
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) == set.end()){
                set.insert(nums[i]);
                curr.push_back(nums[i]);
                if(curr.size() == nums.size()){
                    result.push_back(curr);
                }
                helper(nums,curr);
                set.erase(nums[i]);
                curr.pop_back();
            }
        }
    }
};
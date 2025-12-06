class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    unordered_set<int> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return result;
    }
    void helper(vector<int> nums, int index){
        if(index == nums.size() - 1){
            result.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(i != index and nums[i] == nums[index]) continue;
            swap(nums[i], nums[index]);
            helper(nums, index+1);
        }
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        //result.emplace_back(nums);
        backtrack(nums,result,0);
        return result;
    }
    void backtrack(vector<int>& nums,vector<vector<int>>& result,int first){
        if(first == nums.size()){
            result.emplace_back(nums);
            return;
        }
        for(int i = first; i < nums.size(); i++){
            swap(nums[i],nums[first]);
            backtrack(nums,result,first+1);
            swap(nums[i],nums[first]);
        }
    }
};
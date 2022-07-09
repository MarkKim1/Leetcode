class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result,nums,0);
        return result;
    }
    void backtrack(vector<vector<int>>& result,vector<int>& nums,int start){
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums[i],nums[start]);
            backtrack(result,nums,start+1);
            swap(nums[i],nums[start]);
        }
    }
};
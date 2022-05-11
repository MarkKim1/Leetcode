class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        result.push_back(nums);
        int count = 0;
        permutation(nums,result,sub,count);
        return result;
    }
    void permutation(vector<int>&nums,vector<vector<int>>&result,vector<int>&sub,int count){
        if(find(result.begin(),result.end(),sub) == result.end() && sub.size() == nums.size()){
            result.push_back(sub);
        }
        for(int i = count; i < nums.size(); i++){
            sub.push_back(nums[i]);
            swap(nums[i],nums[count]);
            permutation(nums,result,sub,count+1);
            swap(nums[i],nums[count]);
            sub.pop_back();
        }
        
    }
};
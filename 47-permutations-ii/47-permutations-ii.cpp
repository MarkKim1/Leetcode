class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        result.push_back(nums);
        int count = 0;
        while(next_permutation(nums.begin(),nums.end())){
            result.push_back(nums);
        }
        //permutation(nums,result,sub,count);
        return result;
    }
    void permutation(vector<int>&nums,vector<vector<int>>&result,vector<int>&sub,int count){
        unordered_set<int> set;
        if(find(result.begin(),result.end(),sub) == result.end() && sub.size() == nums.size()){
            result.push_back(sub);
        }
        for(int i = count; i < nums.size(); i++){
            if(set.count(nums[i]) == 1){
                continue;
            }
            set.insert(nums[i]);
            sub.push_back(nums[i]);
            swap(nums[i],nums[count]);
            permutation(nums,result,sub,count+1);
            swap(nums[i],nums[count]);
            sub.pop_back();
        }
        
    }
};
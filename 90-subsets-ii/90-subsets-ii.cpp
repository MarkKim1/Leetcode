class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> sub;
        subsets(nums,0,result,sub);
        return result;
    }
private:
    void subsets(vector<int>&nums,int i,vector<vector<int>>&result,vector<int>&sub){
        if(::find(result.begin(),result.end(),sub) == result.end()){
        result.push_back(sub);
        }
        for(int j = i; j < nums.size(); j++){
            sub.push_back(nums[j]);
            subsets(nums,j+1,result,sub);
            sub.pop_back();
        }
    }
};
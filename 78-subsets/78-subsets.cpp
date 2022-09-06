class Solution {
public:
    vector<vector<int>> result;
    vector<int> sub;
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(sub);
        helper(0,nums,sub);
        return result;
    }
    
   void helper(int i, vector<int>& nums,vector<int>& sub){
       for(int n = i; n < nums.size(); n++){
           sub.push_back(nums[n]);
           result.push_back(sub);
           helper(n+1,nums,sub);
           sub.pop_back();
        }
    }
};
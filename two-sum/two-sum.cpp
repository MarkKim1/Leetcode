class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        int numberToCount = 0;
        for(int i = 0; i < nums.size(); i++){
            numberToCount = target - nums[i];
            
            if(hash.find(numberToCount) != hash.end()){
                return {hash[numberToCount], i};
            }
            hash[nums[i]] = i;
        }
        return{-1,-1};
    }
};
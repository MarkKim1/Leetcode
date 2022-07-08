class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            int targetnum = target-nums[i];
            if(map.find(targetnum) != map.end()){
                return {i,map[targetnum]};
            }
            map[nums[i]] = i ;
        }
        return {0,0};
    }
};
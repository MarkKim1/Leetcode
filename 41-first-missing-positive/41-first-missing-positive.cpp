class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minNum = INT_MAX;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                minNum = min(nums[i],minNum);
                map[nums[i]] = nums[i];
            }
        }
        if(minNum != 1) return 1;
        int smallest = INT_MAX;
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == INT_MAX) continue;
            if(nums[i] > 0 and map.find(nums[i]+1) == map.end()){
                smallest = min(smallest,nums[i] + 1);
            }
        }
        return smallest;
    }
};
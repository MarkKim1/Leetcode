class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        
        for(int i = 0; i < nums.size()-1; i++){
            int first = nums[i];
            if(i == 0 || nums[i] != nums[i-1]){
                int left = i+1;
                int right = nums.size()-1;
                while(left < right){
                    if(first + nums[left] + nums[right] == 0){
                        vector<int> sub = {first,nums[left],nums[right]};
                        result.push_back(sub);
                        while(left < right and nums[left] == nums[left+1]) left++;
                        while(left < right and nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(first + nums[left] + nums[right] < 0){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
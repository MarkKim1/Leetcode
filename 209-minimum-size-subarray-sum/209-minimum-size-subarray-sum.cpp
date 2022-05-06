class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int max_distance = INT_MAX;
        for(int right = 0; right < nums.size(); right++){
            sum +=nums[right];
            while(sum >= target){
                max_distance = min(max_distance,right-left+1);
                sum -=nums[left];
                left++;
                
            }
        }
        
        return (max_distance!= INT_MAX) ? max_distance: 0;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = first + nums[left] + nums[right];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return target-diff;
    }
};
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < k){
                ans = max(ans,sum);
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};
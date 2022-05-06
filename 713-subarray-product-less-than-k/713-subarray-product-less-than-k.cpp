class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pred = 1;
        int left = 0;
        int right = 0;
        int count = 0;
        if(k <= 1){
            return 0;
        }
        for(int i = 0; i < nums.size(); i++){
            pred *= nums[i];
            while(pred >= k){
                pred /=nums[left++];
            }
            count +=i-left+1;
        }
        return count;
    }
};
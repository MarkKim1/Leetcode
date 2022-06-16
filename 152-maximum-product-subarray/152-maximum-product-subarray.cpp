class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int current_num = nums[i];
            int temp = max(current_num,max(max_so_far * current_num, min_so_far * current_num));
            min_so_far = min(current_num,min(max_so_far * current_num, min_so_far * current_num));
            max_so_far = temp;
            
            result = max(result,max_so_far);
            
        }
        return result;
    }
};
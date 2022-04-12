class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int pivot;
        while(left <= right){
            pivot = (left + right)/2;
            if(pivot == left && pivot == right){
                if(nums[pivot] < target) return pivot +1;
                else return pivot;
            }
            if(nums[pivot] == target){
                return pivot;
            }
            else if(nums[pivot] < target){
                left = pivot+1;
            }
            else {
                right = pivot;
            }
        }
        return 0;
    }
};
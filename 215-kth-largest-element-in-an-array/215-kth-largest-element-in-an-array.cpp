class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        return quickSelect(nums,0,nums.size()-1,k);
    }
    int quickSelect(vector<int>& nums, int l, int r, int k){
        int index = partition(nums,l,r);
        if(index == k){
            return nums[index];
        }
        if(index < k){
            return quickSelect(nums,index+1,r,k);
        }
        else{
            return quickSelect(nums,l,index-1,k);
        }
    }
    int partition(vector<int>& nums, int l, int r){
        int x = nums[r], i = l;
        for(int j = l; j <=r-1; j++){
            if(nums[j] <= x){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
};
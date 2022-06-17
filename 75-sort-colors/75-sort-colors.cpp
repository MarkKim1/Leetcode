class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos1 = 0,curr = 0;
        int pos2 = nums.size()-1;
        
        while(curr <= pos2){
            if(nums[curr] == 0){
                swap(nums[curr++],nums[pos1++]);
            }
            else if(nums[curr] == 2){
                swap(nums[curr],nums[pos2--]);
            }else{
                curr++;
            }
        }
    }
};
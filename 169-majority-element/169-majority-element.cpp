class Solution {
public:
    //Boyer-Moore only works with finding majority inside the array when majority count is more than n/2
    //where n is size of vector
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int votes = 0;
        for(int i = 0; i < nums.size(); i++){
            if(votes == 0){
                candidate = nums[i];
                votes = 1;
            }else{
                if(nums[i] == candidate){
                    votes++;
                }else{
                    votes--;   
                }
            }
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate){
                count++;
            }
        }
        if(count > nums.size()/2){
            return candidate;
        }
        return -1;
    }
};
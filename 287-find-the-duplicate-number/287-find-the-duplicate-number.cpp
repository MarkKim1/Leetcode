class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int one = nums[0];
        int two = nums[0];
        while(true){
            one = nums[nums[one]];
            two = nums[two];
            if(one == two) break;
        }
        one = nums[0];
        while(true){
            if(one == two)break;
            one = nums[one];
            two = nums[two];
        }
        return two;
    }
};
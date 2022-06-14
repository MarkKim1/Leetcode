class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tortoise = nums[nums[0]];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[nums[tortoise]];
        }
        hare = 0;
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};
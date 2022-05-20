class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> map;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(++map[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};
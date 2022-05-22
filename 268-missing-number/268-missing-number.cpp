class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i <=nums.size(); i++){
            if(find(nums.begin(),nums.end(),i) != nums.end()){
                continue;
            }
            return i;
        }
        return 0;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int reach = 0;
        int jumpCount = 0;
        int jumpEnd = 0;
        for(int i = 0; i < nums.size()-1; i++){
            reach = max(reach,nums[i] + i);
            if(i == jumpEnd){
                jumpCount++;
                jumpEnd = reach;
            }
            
        }
        return jumpCount;
    }
};
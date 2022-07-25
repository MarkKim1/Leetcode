class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxcur = nums[0];
        int maxresult = nums[0];
        int mincur = nums[0];
        int minresult = nums[0];
        int total = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxcur = max(maxcur+nums[i],nums[i]);
            maxresult = max(maxcur,maxresult);
            mincur = min(mincur+nums[i],nums[i]);
            minresult = min(mincur,minresult);
            total +=nums[i];
        }
        return maxresult > 0 ? max(total-minresult,maxresult) : maxresult;
    }
};
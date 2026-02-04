class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long res = -2e18;
        for(int i = 1; i < nums.size()-2; ){
            // find the middle p - q decreasing 
            int a = i, b = i;
            long long between = nums[a];
            while(b + 1 < nums.size() && nums[b] > nums[b + 1]){
                between += nums[++b];
            }
            if(a == b){i++; continue;}
            long long left = 0, leftmax = INT_MIN;
            long long right = 0, rightmax = INT_MIN;
            int c = b;
            // find the maximum value strictly increasing from left to a
            while(a - 1 >= 0 && nums[a - 1] < nums[a]){
                left += nums[--a];
                leftmax = max(left,leftmax);
            }
            if(i == a){i++; continue;}

            //find the maximum value stricktly increasing from b + 1 to nums.size() - 1
            while(b + 1 < nums.size() && nums[b] < nums[b + 1]){
                right += nums[++b];
                rightmax = max(rightmax, right);
            } 
            if(b == c) {i++; continue;}
            res = max(res,(long long)between + rightmax + leftmax);
            i = b;
        }
        return res;
    }
};
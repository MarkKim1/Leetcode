class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> sums(nums.size());
        long long total = 0;
        sums[0] = nums[0];
        long long n = nums.size();
        int biggest = INT_MAX;
        long long ans = 0;
        for(int i = 1; i < n; i++ ){
            sums[i] = sums[i-1] + nums[i];
        }
        total = sums[n-1];
        for(int i = 0; i < n; i++){
            int num = abs((sums[i]/(i+1)) - ((total-sums[i])/(n-i-1 == 0 ? 1 : n-i-1)));
            if(num < biggest){
                biggest = num;
                ans = i;    
            }
        }
        return int(ans);
    }
};
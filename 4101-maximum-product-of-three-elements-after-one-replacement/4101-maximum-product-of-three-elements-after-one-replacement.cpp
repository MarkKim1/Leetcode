class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long a = 0, b = 0;
        for(long long ax : nums){
            ax = llabs(ax);
            if(ax >= a){
                b = a;
                a = ax;
            }
            else if(ax > b) b = ax;
        }
        return a * b * 100000LL;
    }
};
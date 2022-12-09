class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0,0}};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum +=nums[i];
            sum %= k;
            if(map.find(sum) != map.end()){
                if(i-map[sum]+1 > 1) return true;
            }else{
                map[sum] = i+1;
            }
        }
        return false;
    }
};
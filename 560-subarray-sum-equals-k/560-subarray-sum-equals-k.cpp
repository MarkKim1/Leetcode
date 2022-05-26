class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count = 0;
        int sub = 0;
        
        map[sub] = 1;
        
        for(int i =0; i < nums.size(); i++){
            sub +=nums[i];
            int find = sub-k;
            if(map.find(find) != map.end()){
                count +=map[find];
            }
            map[sub]++;
        }
        return count;
    }
};
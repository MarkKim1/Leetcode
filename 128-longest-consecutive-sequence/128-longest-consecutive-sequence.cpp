class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<bool> visited(nums.size());
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }
        int result = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            if(map.find(temp-1) == map.end()){
                result++;
                while(map.find(temp+1) != map.end()){
                    result++;
                    temp+=1;
                }
                ans = max(ans,result);
            }
            result = 0;
        }
        return ans;
    }
};
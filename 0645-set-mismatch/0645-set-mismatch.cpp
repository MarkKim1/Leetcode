class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        int count = 1;
        vector<int> ans;
        int dup = -1;
        int loss = -1;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(count) != map.end() and map[count] > 1){
                dup = count;
            }
            else if(map.find(count) == map.end()){
                loss = count;
            }
            count++;
        }
        return {dup,loss};
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> map;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]] > 0){
                continue;
            }else{
                map[nums[i]]++;
                count++;
            }
        }
        int size = map.size();
        int i = 0;
        for(auto each : map){
            nums[i] = each.first;
            i++;
        }
        return count;
    }
};
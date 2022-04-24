class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(hash[nums[i]] != 1){
                nums.erase(nums.begin() +i);
                hash[nums[i]]--;
                i--;
            }
        }
        return nums.size();
    }
};
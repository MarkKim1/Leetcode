class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int left = 0;
        int right = 0;
        vector<string> result;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] + 1 != nums[i]){
                if(left == right){
                    result.push_back(to_string(nums[left]));
                }else{
                    result.push_back(to_string(nums[left]) + "->"+to_string(nums[right]));
                }
                left = right = i;
            }else{
                right++;
            }
        }
        if(left == right){
            result.push_back(to_string(nums[left]));
        }else{
            result.push_back(to_string(nums[left]) + "->"+to_string(nums[right]));
        }
        return result;
    }
};
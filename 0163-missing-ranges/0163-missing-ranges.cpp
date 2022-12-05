class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        if(nums.empty()){
            if(lower == upper){
                ans.push_back(to_string(lower));
                return ans;
            }else{
                string sub = to_string(lower) + "->" + to_string(upper);
                ans.push_back(sub);
                return ans;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                if(nums[i] > lower){
                    if(lower + 1 == nums[i]){
                        ans.push_back(to_string(lower));
                    }else{
                        ans.push_back(to_string(lower) + "->" + to_string(nums[i] -1));
                    }
                }
            }
            if(i == nums.size()-1){
                if(nums[i] + 1 > upper){
                    continue;
                }else if(nums[i] + 1 == upper){
                    ans.push_back(to_string(nums[i]+1));
                }else{
                    string sub = to_string(nums[i]+1) + "->" + to_string(upper);
                    ans.push_back(sub);
                }
            }else{
                if(nums[i]+1 == nums[i+1]){
                    continue;
                }
                else if(nums[i] + 1 == nums[i+1]-1){
                    ans.push_back(to_string(nums[i]+1));
                }else{
                    string sub = to_string(nums[i]+1) + "->" + to_string(nums[i+1]-1);
                    ans.push_back(sub);
                }
            }
        }
        return ans;
    }
};
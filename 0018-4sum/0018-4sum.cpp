class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){
            return result;
        }
        sort(nums.begin(),nums.end());
        unordered_set<int> set2;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                long long a = nums[i];
                long long b = nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    if(a + b + (long long)nums[left] + (long long)nums[right] == target){
                        result.push_back({(int)a,(int)b,(int)nums[left],(int)nums[right]});
                        right--;
                        left++;
                        while (left < right && nums[left-1] == nums[left]){
                            ++left;
                        }
                    }else if(a + b + nums[left] + nums[right] > target){
                        right--;
                    }else if(a + b + nums[left] + nums[right] < target){
                        left++;
                    }
                }
                while(j+1 < nums.size() and nums[j] == nums[j+1]){
                    j++;
                }
            }
            while(i+1 < nums.size() and nums[i] == nums[i+1]){
                i++;
            }
        }
        return result;
    }
};
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size(); int ans = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            int curr = 0, sum = INT_MAX;
            for(int i = 0; i < n - 1; i++){
                if(sum > nums[i] + nums[i + 1]){
                    curr = i; sum = nums[i] + nums[i + 1];
                }
            }
            vector<int> temp;
            for(int j = 0; j < curr; j++){
                temp.push_back(nums[j]);
            }
            temp.push_back(sum);
            for(int j = curr + 2; j < n; j++){
                temp.push_back(nums[j]);
            }
            swap(nums,temp);
            ans++;
            n--;
        }
        return ans;
    }
};
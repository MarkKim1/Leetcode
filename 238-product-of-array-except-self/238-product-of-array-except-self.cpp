class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0] = 1;
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }
        right[n-1] = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i = 0; i < nums.size(); i++){
            answer.emplace_back(left[i]*right[i]);
        }
        
        return answer;
    }
};
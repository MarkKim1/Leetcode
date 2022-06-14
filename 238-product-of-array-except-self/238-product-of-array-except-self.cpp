class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        // vector<int> left(n,0);
        // vector<int> right(n,0);
        
        answer[0] = 1;
        for(int i = 1; i < n; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }
        int prev = 1;
        for(int i = nums.size()-2; i >=0; i--){
            answer[i] = answer[i] * nums[i+1] * prev;
            prev = prev * nums[i+1];
        }
        
        return answer;
    }
};
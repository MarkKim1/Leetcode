class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> scores(nums.size());
        dq.push_back(0);
        scores[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            while(!dq.empty() and dq.front() < i-k){
                dq.pop_front();
            }
            scores[i] = nums[i] + scores[dq.front()];
            while(!dq.empty() and scores[i] >= scores[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return scores[nums.size()-1];
    }
};
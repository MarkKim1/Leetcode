class Solution {
public:
    vector<int> origin;
    vector<int> shuffled;
    Solution(vector<int>& nums) {
        this->origin = nums;
        this->shuffled = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < shuffled.size(); i++){
            int pos = rand() % (shuffled.size()-1);
            swap(shuffled[pos],shuffled[i]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
class Solution {
public:
    vector<int> original;
    vector<int> shuffled;
    Solution(vector<int>& nums) {
        this->original = nums;
        this->shuffled = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < shuffled.size(); i++){
            int random_index = rand() % (shuffled.size()-1);
            swap(shuffled[i],shuffled[random_index]);
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
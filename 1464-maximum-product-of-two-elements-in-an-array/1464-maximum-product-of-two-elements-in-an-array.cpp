class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxheap;
        
        for(int i = 0; i < nums.size(); i++){
            maxheap.push(nums[i]);
        }
        int a = maxheap.top() - 1;
        maxheap.pop();
        return a * (maxheap.top() - 1);
    }
};
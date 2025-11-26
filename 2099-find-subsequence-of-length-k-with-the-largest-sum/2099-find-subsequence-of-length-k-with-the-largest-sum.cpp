class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(int i = 0; i < nums.size(); i++){
            maxheap.push(make_pair(nums[i], i));
        }
        vector<int> result;
        for(int i = k - 1; i >= 0; i--){
            int num = maxheap.top().first;
            int index = maxheap.top().second;
            minheap.push(make_pair(index, num));
            maxheap.pop();
        }
        for(int i = k - 1; i >= 0; i--){
            result.push_back(minheap.top().second);
            minheap.pop();
        }
        return result;        
    }
};
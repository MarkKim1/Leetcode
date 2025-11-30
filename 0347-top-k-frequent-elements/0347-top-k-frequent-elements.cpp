class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto each : map){
            pq.push({each.second, each.first});
        }
        vector<int> ans;
        while(k--){
            auto curr = pq.top();
            ans.push_back(curr.second);
            pq.pop();
        }
        return ans;
    }
};
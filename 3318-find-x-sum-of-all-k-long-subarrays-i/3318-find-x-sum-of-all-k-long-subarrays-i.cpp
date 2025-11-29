class Solution {
public:
    using int2 = pair<int,int>;
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i = 0; i < k; i++){
            map[nums[i]]++;
        }
        result.push_back(calculate(map,x));
        
        for(int i = 1; i < nums.size() - k + 1; i++){
            map[nums[i - 1]]--;
            map[nums[i + k - 1]]++;
            result.push_back(calculate(map,x));
        }
        return result;
    }
    int calculate(unordered_map<int,int>& map, int x){
        priority_queue<int2> pq;
        for(auto& each : map){
            pq.push({each.second, each.first});
        }
        int result = 0;
        while(x-- and !pq.empty()){
            auto curr = pq.top();
            pq.pop();
            result += curr.second * curr.first;            
        }
        return result;
    }
};
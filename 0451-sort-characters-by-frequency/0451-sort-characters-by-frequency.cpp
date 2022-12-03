class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> pq;
        for(auto c : s){
            map[c]++;
        }
        for(auto each : map){
            pq.push({each.second,each.first});
        }
        string ans = "";
        while(!pq.empty()){
            for(int i = 0; i < pq.top().first; i++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};
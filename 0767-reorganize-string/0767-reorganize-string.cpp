class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> pq;
        for(char a : s){
            map[a]++;
        }
        for(auto each : map){
            pq.push({each.second, each.first});
        }
        string result = "";
        while(!pq.empty()){
            
            if(pq.size() == 1){
                if(pq.top().first > 1){
                    return "";
                }
                return result + pq.top().second;
            }
            
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            
            result += first.second;
            result += second.second;
            
            first.first--;
            if(first.first >= 1){
                pq.push(first);    
            }
            second.first--;
            if(second.first >= 1){
                pq.push(second);    
            }
        }
        return result;
    }
};
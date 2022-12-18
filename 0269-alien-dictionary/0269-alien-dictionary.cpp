class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,int> indegree;
        unordered_map<char,unordered_set<char>> graph;
        //initialize the indegree
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                char c = words[i][j];
                indegree[c] = 0;
            }
        }
        //make a graph and modify the indegree
        for(int i = 0; i < words.size()-1; i++){
            string curr = words[i];
            string next = words[i+1];
            int len = min(curr.size(),next.size());
            for(int j = 0; j < len; j++){
                if(curr[j] != next[j]){
                    unordered_set<char> set = graph[curr[j]];
                    if(set.find(next[j]) == set.end()){
                        indegree[next[j]]++;
                        graph[curr[j]].insert(next[j]);
                    }
                    break;
                }
                if(j == len - 1 and curr.size() > next.size()) return "";
            }
            
        }
        queue<char> q;
        string result = "";
        for(auto& each : indegree){
            if(each.second == 0){
                q.push(each.first);
            }
        }
        while(!q.empty()){
            char curr = q.front();
            q.pop();
            result.push_back(curr);
            for(auto each : graph[curr]){
                indegree[each]--;
                if(indegree[each] == 0){
                    q.push(each);
                }
            }
        }
        return result.size() == indegree.size() ? result : "";
    }
};
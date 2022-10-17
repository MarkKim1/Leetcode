class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> adj;
        unordered_map<int,vector<int>> graph;
        vector<int> result;
        if(n <= 2){
            for(int i = 0; i < n; i++){
                result.push_back(i);
            }
            return result;
        }
        for(int i = 0; i < edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]]++;
            adj[edges[i][1]]++;
        }
        queue<int> q;
        for(auto& a: adj){
            if(a.second == 1){
                q.push(a.first);
                a.second--;
            }
        }
        while(!q.empty()){
            int size = q.size();
            result.clear();
            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                for(auto neighbor : graph[curr]){
                    adj[neighbor]--;
                    if(adj[neighbor] == 1){
                        q.push(neighbor);
                    }
                }
            }
        }
        return result;
    }
};
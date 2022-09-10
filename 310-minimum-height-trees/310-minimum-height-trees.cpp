class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> adj(n,0);
        vector<int> result;
        if(n <= 2){
            for(int i =0 ; i < n; i++){
                result.push_back(i);
            }
            return result;
        }
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]]++;
            adj[edges[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(adj[i] == 1){
                adj[i]--;
                q.push(i);
            }
        }
        while(!q.empty()){
            int size = q.size();
            result.clear();
            for(int i = 0; i < size; i++){
                int first = q.front();
                q.pop();
                result.push_back(first);
                for(int neighbor : graph[first]){
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
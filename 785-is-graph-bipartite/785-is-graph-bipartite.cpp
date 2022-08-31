class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        vector<bool> visited(n);
        //  0 = uncolored
        //  1 = Blue
        // -1 = Red
        for(int i = 0; i < n; i++){
            if(!color[i]){ // if color[i] is false which is uncolored
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if(visited[node]) continue;
                    visited[node] = true;
                    for(auto nei : graph[node]){
                        if(color[nei] == color[node]){
                            return false;
                        }
                        color[nei] = -color[node];
                        q.push(nei);
                    }
                    
                }
            }
        }
        return true;
    }
};
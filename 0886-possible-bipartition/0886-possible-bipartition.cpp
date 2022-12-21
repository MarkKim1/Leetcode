class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        vector<int> color(n+1,-1);
        for(int i = 0; i < dislikes.size(); i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                if(bfs(i,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool bfs(int source, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(source);
        color[source] = 0; // color[source] is red
        
        while(!q.empty()){
            int curr_node = q.front(); // 1
            q.pop();
            for(auto neighbors : graph[curr_node]){
                if(color[neighbors] == color[curr_node]) return false;
                if(color[neighbors] == -1){
                    color[neighbors] = 1 - color[curr_node];
                    q.push(neighbors);
                }
            }
        }
        return true;
    }
};
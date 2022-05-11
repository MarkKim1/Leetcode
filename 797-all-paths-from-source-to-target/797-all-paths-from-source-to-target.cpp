class Solution {
    int target;
    vector<vector<int>> result;
    vector<int>sub;
    public:
    void dfs(vector<vector<int>>&graph, int curr = 0){
        sub.push_back(curr);
        if(curr == target){
            result.push_back(sub);
        }else{
            for(int node:graph[curr]){
                dfs(graph,node);
            }
        }
        sub.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(graph);
        return result;
    }
};
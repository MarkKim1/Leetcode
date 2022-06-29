class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> sub;
        int size = graph.size()-1;
        dfs(0,graph,sub,size,result);
        return result;
    }
     void dfs(int i, vector<vector<int>>& graph, vector<int> sub,int size,vector<vector<int>>& result){
         sub.push_back(i);
         if(i == size) {
             result.push_back(sub);
             return;
         }
         for(int j = 0; j < graph[i].size(); j++){
             dfs(graph[i][j],graph,sub,size,result);
         }
         sub.pop_back();
    }
};
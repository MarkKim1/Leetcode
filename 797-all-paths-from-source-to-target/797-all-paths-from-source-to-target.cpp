class Solution {
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> sub;
        vector<vector<int>> result;
        dfs(sub,result,0,graph);
        return result;
    }
    void dfs(vector<int>& sub, vector<vector<int>>& result, int curr,vector<vector<int>>& graph){
        if(curr == graph.size()-1){
            sub.push_back(graph.size()-1);
            result.push_back(sub);
            return;
        }
        sub.push_back(curr);
        for(int i = 0; i < graph[curr].size(); i++){
            
            dfs(sub,result,graph[curr][i],graph);
            sub.pop_back();
        }
    }
};
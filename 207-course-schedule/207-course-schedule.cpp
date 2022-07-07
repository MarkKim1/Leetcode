class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> result(n);
        vector<int> visited(n, 0);
        for(int i = 0; i < pre.size(); i++){
            result[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                if(isCycle(i,result,visited))
                return false;
            }
        }
        return true;
    }
    bool isCycle(int curr, vector<vector<int>>& result,vector<int>& visited){
        if(visited[curr] == 2){
            return true;
        }
        visited[curr] = 2;
        for(int i = 0; i < result[curr].size(); i++){
            if(visited[result[curr][i]] != 1){
                if(isCycle(result[curr][i],result,visited)){
                    return true;
                }
            }
        }
        visited[curr] = 1;
        return false;
    }
};
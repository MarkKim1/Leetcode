class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> result(numCourses);
        vector<int> visited(numCourses,0);
        for(int i = 0; i < pre.size(); i++){
            result[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(isCycle(result,visited,i))
                return false;
            }
        }
        return true;
    }
    bool isCycle(vector<vector<int>>& result,vector<int>& visited,int curr){
        if(visited[curr] == 2){
            return true;
        }
        visited[curr] = 2;
        for(int i = 0; i < result[curr].size(); i++){
            if(visited[result[curr][i]] != 1){
                if(isCycle(result,visited,result[curr][i])){
                    return true;
                }      
            }  
        }
        visited[curr] = 1;
        return false;
    }
    
};
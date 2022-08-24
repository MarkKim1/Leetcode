class Solution {
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> graph(numCourses);
        stack<int> result;
        vector<int> ans;
        vector<bool> todo(numCourses,false),done(numCourses,false);
        for(vector<int> a : pre){
            graph[a[1]].push_back(a[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!DFS(graph,result,todo,done,i)){
                return ans;
            }
        }
        while(!result.empty()){
            ans.push_back(result.top());
            result.pop();
        }
        return ans;
    }
    bool DFS(vector<vector<int>>& graph,stack<int>& result, vector<bool>& todo, vector<bool>& done,int node){
        if(todo[node]){
            return false;
        }
        if(done[node]){
            return true;
        }
        todo[node] = true;
        done[node] = true;
        for(auto a : graph[node]){
            if(DFS(graph,result,todo,done,a) == false){
                return false;
            }
        }
        result.push(node);
        todo[node] = false;
        return true;
    }
};
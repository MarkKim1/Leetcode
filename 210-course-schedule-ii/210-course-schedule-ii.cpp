class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        for(int i = 0; i < pre.size(); i++){
            graph[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto a : graph[curr]){
                if(--indegree[a] == 0){
                    q.push(a);
                }
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};
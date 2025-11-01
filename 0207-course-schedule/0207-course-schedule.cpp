class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto each : prerequisites){
            adj[each[1]].push_back(each[0]);
            degree[each[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            n--;
            for(auto each : adj[curr]){
                if(--degree[each] == 0){
                    q.push(each);
                }
            }
        }
        return n == 0;
    }
};
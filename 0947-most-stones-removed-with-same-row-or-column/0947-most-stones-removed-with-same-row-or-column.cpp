class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> adj(stones.size());
        for(int i = 0; i < stones.size(); i++){
            for(int j = i+1; j < stones.size(); j++){
                if(isConnected(stones[i],stones[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int remove = 0;
        vector<int> visited(stones.size(),0);
        for(int i = 0; i < stones.size(); i++){
            if(visited[i] == 0){
                remove++;
                dfs(stones,adj,visited,i);
            }
        }
        return stones.size()-remove;
    }
private:
    bool isConnected(vector<int>& a, vector<int>& b){
        return a[0] == b[0] || a[1] == b[1];
    }
    void dfs(vector<vector<int>>& stones, vector<vector<int>>& adj, vector<int>& visited, int start){
        visited[start] = 1;
        for(auto each : adj[start]){
            if(visited[each] == 0){
                dfs(stones,adj,visited,each);
            }
        }
    }
};
class Solution {
public:
    int ans = -1;
    
    void dfs(vector<int>& edges, unordered_map<int,int>& map,vector<int>& visited, int i){
        visited[i] = true;
        int next = edges[i];
        if(next != -1 and !visited[next]){
            map[next] = map[i] + 1;
            dfs(edges,map,visited,next);
        }else if(next != -1 and map.count(next)){
            ans = max(ans,map[i] - map[next] + 1);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n);
        for(int i = 0; i < edges.size(); i++){
            if(!visited[i]){
                unordered_map<int,int> map;
                map[i] = 1;
                dfs(edges,map,visited,i);
            }
        }
        return ans;
    }
};
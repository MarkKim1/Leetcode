struct INFO{
    int u = 0,v = 0,w = 0;
};

class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<INFO> graph;
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph.push_back({u,v,w});
        }
        
        solve(graph,n,k,dist);
        int result = INT_MIN;
        for(int i = 1; i < dist.size(); i++){
            result = max(result,dist[i]);
        }
        return result == INT_MAX ? -1 : result;
    }
    void solve(vector<INFO> graph, int n, int k,vector<int>& dist){
        dist[k] = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < graph.size(); j++){
                int u = graph[j].u;
                int v = graph[j].v;
                int w = graph[j].w;
                if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
};
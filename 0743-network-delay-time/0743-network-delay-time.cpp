class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        for(int i = 0; i < n-1; i++){
            for(auto each : times){
                int u = each[0];
                int v = each[1];
                int w = each[2];
                if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        int result = INT_MIN;
        for(int i = 1; i < dist.size(); i++){
            result = max(dist[i],result);
        }
        return result == INT_MAX ? -1 : result;
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       vector<unordered_set<int>> graph(n);
        for(int i = 0; i < roads.size(); i++){
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int network = graph[i].size() + graph[j].size();
                if(graph[i].count(j)){
                    network--;
                }
                ans = max(ans,network);
            }
        }
        return ans;
    }
};
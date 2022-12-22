class Solution {
public:
    unordered_map<int,unordered_set<int>> graph;
    vector<int> count;
    vector<int> res;
    int size;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(vector<int> edge : edges){
            graph[edge[1]].insert(edge[0]);
            graph[edge[0]].insert(edge[1]);
        }
        size = n;
        count.assign(n,1);
        res.assign(n,0);
        dfs(0,-1);
        dfs2(0,-1);
        return res;
    }
    void dfs(int root, int pre){
        for(auto child : graph[root]){
            if(child == pre){
                continue;
            }
            dfs(child,root);
            count[root] += count[child];
            res[root] += res[child] + count[child];
        }
    }
    void dfs2(int root, int pre){
        for(auto child : graph[root]){
            if(child == pre){
                continue;
            }
            res[child] = res[root] - count[child] + size - count[child];
            dfs2(child,root);
        }
    }
};
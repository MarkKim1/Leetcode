class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dfs(color,graph,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool dfs(vector<int>& color, vector<vector<int>>& graph, int curr_node){
        if(color[curr_node] > 0){
            return color[curr_node] == 2;
        }
        color[curr_node] = 1;
        for(auto neighbor: graph[curr_node]){
            if(color[curr_node] == 2){
                continue;
            }
            if(color[neighbor] == 1 or !dfs(color,graph,neighbor)){
                return false;
            }
        }
        color[curr_node] = 2;
        return true;
    }
};

// class Solution {
//     public List<Integer> eventualSafeNodes(int[][] graph) {
//         int N = graph.length;
//         int[] color = new int[N];
//         List<Integer> ans = new ArrayList();

//         for (int i = 0; i < N; ++i)
//             if (dfs(i, color, graph))
//                 ans.add(i);
//         return ans;
//     }

//     // colors: WHITE 0, GRAY 1, BLACK 2;
//     public boolean dfs(int node, int[] color, int[][] graph) {
//         if (color[node] > 0)
//             return color[node] == 2;

//         color[node] = 1;
//         for (int nei: graph[node]) {
//             if (color[node] == 2)
//                 continue;
//             if (color[nei] == 1 || !dfs(nei, color, graph))
//                 return false;
//         }

//         color[node] = 2;
//         return true;
//     }
// }
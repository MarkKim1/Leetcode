class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> root(n,0);
        set<int> set;
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
        for(int i = 0; i < edges.size(); i++){
            int rootx = find(edges[i][0],root);
            int rooty = find(edges[i][1],root);
            if(rootx != rooty){
                root[rooty] = rootx;
                n-=1;
            }
        }
        return n;
        
    }
    int find(int vertex, vector<int>& root){
        if(vertex == root[vertex]){
            return vertex;
        }
        return root[vertex] = find(root[vertex],root);
    }
};
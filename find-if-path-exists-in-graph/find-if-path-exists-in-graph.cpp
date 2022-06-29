class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> root(n,0);
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
        
        for(int i = 0; i < edges.size(); i++){
            int rootx = find(edges[i][0],root);
            int rooty = find(edges[i][1],root);
            if(rootx != rooty){
                root[rooty] = rootx;
            }
        }
        int start = find(source,root);
        int end = find(destination,root);
        if(start != end) return false;
        return true;
        
    }
    
    int find(int x, vector<int>& root){
        if(x == root[x]){
            return x;
        }
        return root[x] = find(root[x],root);
    }
};
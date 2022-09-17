class Solution {
public:
    vector<int> vertex;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        for(int i = 0; i < n; i++){
            vertex.push_back(i);
        }
        for(auto edge: edges){
            if(!uf(edge[0],edge[1])){
                return false;
            }
        }
        return true;
    }
    bool uf(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        vertex[rooty] = rootx;
        if(rootx == rooty){
            return false;
        }
        return true;
    }
    int find(int a){
        if(a == vertex[a]){
            return a;
        }
        return vertex[a] = find(vertex[a]);
    }
};
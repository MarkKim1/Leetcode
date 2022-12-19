class unionFind{
    public:
    vector<int> root;
    unionFind(int x){
        for(int i = 0; i < x; i++){
            root.push_back(i);
        }
    }
    void makeUnion(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx != rooty){
            root[rooty] = rootx;
        }
    }
    int find(int x){
        if(root[x] == x){
            return x;
        }
        root[x] = find(root[x]);
        return root[x];
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        unionFind uf(n);
        for(int i = 0; i < edges.size(); i++){
            uf.makeUnion(edges[i][0],edges[i][1]);
        }
        for(int i = 0; i < edges.size(); i++){
            uf.makeUnion(edges[i][0],edges[i][1]);
        }
        
        return uf.root[source] == uf.root[dest];
    }
};
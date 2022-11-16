class UnionFind {
    public:
    vector<int> root;
    UnionFind(int x){
        for(int i = 0; i < x; i++){
            root.push_back(i);
        }
    }
    bool Union(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y){
            return true;
        }
        if(x != y){
            root[y] = x;
        }
        return false;
    }
    int find(int x){
        if(root[x] == x){
            return x;
        }
        return root[x] = find(root[x]);
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(int i = 0; i < edges.size(); i++){
            if(uf.Union(edges[i][0],edges[i][1])){
                return false;
            }
        }
        int start = 0;
        for(int i = 0; i < n; i++){
            if(start == 1 and uf.find(i) == i){
                return false;
            }
            if(start == 0 and uf.find(i) == i){
                start = 1;
            }
        }
        return true;
    }
};
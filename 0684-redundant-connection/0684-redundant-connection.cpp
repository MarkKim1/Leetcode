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
        if(x == y) return true;
        root[y] = x;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> result;
        UnionFind uf(edges.size()+1);
        for(int i = 0; i < edges.size(); i++){
            if(uf.Union(edges[i][0],edges[i][1])){
                result.push_back({edges[i][0],edges[i][1]});
            }
        }
        return result.back();
        
    }
};
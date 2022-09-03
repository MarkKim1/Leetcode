class DSU{
public:
    vector<int> node;
    DSU(int x){
        for(int i = 0; i < x; i++){
            node.push_back(i);
        }
    }
    bool uf(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx == rooty){
            return false;
        }else{
            node[rootx] = rooty;
        }
        return true;
    }
    int find(int x){
        if(node[x] == x){
            return x;
        }
        return find(node[x]);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        DSU dsu(edges.size()+1);
        for(int i = 0; i < edges.size(); i++){
            if(dsu.uf(edges[i][0],edges[i][1])){
                continue;
            }else{
                ans.push_back(edges[i]);
            }
        }
        return ans.back();
    }
};
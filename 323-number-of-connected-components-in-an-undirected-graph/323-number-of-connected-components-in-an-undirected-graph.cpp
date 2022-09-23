class DSU{
    public:
    void find_root(unordered_set<int>&);
    vector<int> root;
    vector<int> rank;
    DSU(int x){
        for(int i = 0; i < x; i++){
            root.push_back(i);
            rank.push_back(1);
        }
    }
    int Union(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx == rooty){
            return 0;
        }else{
            if(rank[rootx] > rank[rooty]){
                rank[rootx] += rank[rooty];
                root[rooty] = rootx;
            }else{
                rank[rooty] += rank[rootx];
                root[rootx] = rooty;
            }
            return 1;
        }
    }
    int find(int x){
        if(x == root[x]){
            return x;
        }
        return root[x] = find(root[x]);
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        int result = n;
        for(int i = 0; i < edges.size(); i++){
            result -= dsu->Union(edges[i][0],edges[i][1]);
        }
        return result;
    }
};
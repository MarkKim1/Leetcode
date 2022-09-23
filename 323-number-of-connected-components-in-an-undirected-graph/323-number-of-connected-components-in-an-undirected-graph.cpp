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
    void Union(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx != rooty){
            root[rooty] = rootx;
        }
    }
    int find(int x){
        if(x == root[x]){
            return x;
        }
        return root[x] = find(root[x]);
    }
};
void DSU::find_root(unordered_set<int>& set){
    for(int i = 0; i < root.size(); i++){
        set.insert(find(root[i]));
    }
}
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //sort(edges.begin(),edges.end());
        DSU* dsu = new DSU(n);
        unordered_set<int> set;
        for(int i = 0; i < edges.size(); i++){
            dsu->Union(edges[i][0],edges[i][1]);
        }
        dsu->find_root(set);
        return set.size();
    }
};
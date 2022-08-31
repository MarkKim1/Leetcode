class DSU{
    public:
    vector<int> parents;
    DSU(int x){
        for(int i = 0; i < x; i++){
            parents.push_back(i);
        }
    }
    int find(int x){
        if(x == parents[x]){
            return x;
        }
        return find(parents[x]);
    }
    void uf(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx != rooty){
            parents[rootx] = rooty;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU *dsu = new DSU(4*n*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int root = 4*(i*n+j);
                char val = grid[i][j];
                if(val != '\\'){       
                    dsu->uf(root + 0, root + 1);
                    dsu->uf(root + 2, root + 3);
                }
                if(val != '/'){
                    dsu->uf(root + 0, root + 2);
                    dsu->uf(root + 1, root + 3);
                }
                if(i + 1 < n){
                    dsu->uf(root + 3,(root + 4 * n) + 0);
                }
                if(j + 1 < n){
                    dsu->uf(root + 2, (root + 4) + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 4 * n * n; i++){
            if(i == dsu->find(i))
                ans++;
        }
        return ans;
    }   
};
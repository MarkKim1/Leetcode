class Solution {
public:
    vector<int> root;
    vector<bool> result;
    int rest_cables = 0;
    int makeConnected(int n, vector<vector<int>>& connections) {
        this->result.resize(n,false);
        this->root.resize(n);
        for(int i = 0; i < root.size(); i++){
            root[i] = i;
        }
        for(int i = 0; i < connections.size(); i++){
            unionset(connections[i][0],connections[i][1]);
        }
        int ans = 0;
        for(int i = 0; i < root.size(); i++){
            if(root[i] == i){
                ans++;
            }
        }
        return ans-1 > rest_cables ? -1 : ans-1;
    }
    void unionset(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx != rooty){
            root[rootx] = rooty;
        }else if(rootx == rooty){
            rest_cables++;
        }
    }
    int find(int x){
        if(root[x] == x){
            return root[x];
        }
        return root[x] = find(root[x]);
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 0) return true;
        if(n-1 != edges.size()) return false;
        vector<int> a(n,0);
        for(int i = 0; i < n; i ++){
            a[i] = i;
        }
        for(int i = 0; i < edges.size(); i++){
            int first = edges[i][0];
            int second = edges[i][1];
            while(first != a[first]) first = a[first];
            while(second != a[second]) second = a[second];
            a[second] = first;
            if(first == second) return false;
        }
        return true;
    }
};
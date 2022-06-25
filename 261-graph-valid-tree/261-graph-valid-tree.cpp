class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 0) return true;
        if(n-1 != edges.size()) return false;
        vector<int> nodes(n,0);
        for(int i = 0; i < n; i++){
            nodes[i] = i;
        }
        
        for(int i = 0; i < edges.size(); i++){
            int A = find(edges[i][0],nodes);
            int B = find(edges[i][1],nodes);
            nodes[A] = B;
            if(A == B) return false;
        }
        return true;
    }
    
    int find(int a,vector<int>& nodes){
        if(a == nodes[a]){
            return nodes[a];
        }
        return a = find(nodes[a],nodes);
    }
};
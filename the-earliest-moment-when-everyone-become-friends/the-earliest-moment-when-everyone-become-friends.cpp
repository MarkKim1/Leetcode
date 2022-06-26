class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        vector<int> root(n,0);
        sort(logs.begin(),logs.end());
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
        
        for(int i = 0; i < logs.size(); i++){
            int rootx = find(logs[i][1],root);
            int rooty = find(logs[i][2],root);
            if(rootx != rooty){
                n--;
                if(n == 1) return logs[i][0];
                root[rootx] = rooty;
            }
        }
        return -1;
    }
    int find(int vertex, vector<int>& root){
        if(vertex == root[vertex]){
            return vertex;
        }
        return root[vertex] = find(root[vertex],root);
    }
};
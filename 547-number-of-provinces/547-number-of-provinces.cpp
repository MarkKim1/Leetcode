class Solution {
public:
    vector<int> graph;
    int result;
    int findCircleNum(vector<vector<int>>& isConnected) {
        this->result = isConnected.size();
        if(isConnected.size() == 1){
            return 1;
        }
        this->graph.resize(isConnected.size());
        for(int i = 0; i < graph.size(); i++){
            graph[i] = i;
        }
        for(int i = 0 ; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[i].size(); j++){
                if(isConnected[i][j] == 1){
                    unionfind(i,j);
                }
            }
        }
        return result;
    }
    void unionfind(int a,int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx != rooty){
            graph[rootx] = rooty;
            result--;
        }
    }
    int find(int x){
        if(graph[x] == x){
            return graph[x];
        }
        return graph[x] = find(graph[x]);
    }
};
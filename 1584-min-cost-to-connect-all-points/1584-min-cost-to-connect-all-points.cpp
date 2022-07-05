class UnionFind{
  public:
    vector<int> root;
    vector<int> rank;
    
    UnionFind(int size){
        this->root = vector<int>(size);
        this->rank = vector<int>(size);
        for(int i = 0; i < size; i++){
            root[i] = i;
            rank[i] = 0;
        }
    }
    int find(int node){
        if(node == root[node]){
            return root[node];
        }
        return root[node] = find(root[node]);
    }
    bool join(int node1, int node2){
        int group1 = find(node1);
        int group2 = find(node2);
        if(group1 == group2){
            return false;
        }
        if(rank[group1] > rank[group2]){
            root[group2] = group1;
        }else if(rank[group1] < rank[group2]){
            root[group1] = group2;
        }else{
            root[group1] = group2;
            rank[group2]++;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        int a = 0;
        int x = 0;
        int y = 0;
        vector<pair<int,pair<int,int>>> fucking_graph;
        for(int currNode = 0; currNode < size; currNode++){
            for(int nextNode = currNode+1; nextNode < size; nextNode++){
                a = abs(points[currNode][0] - points[nextNode][0]) + 
                          abs(points[currNode][1] - points[nextNode][1]);
                
                fucking_graph.push_back({a,{currNode,nextNode}});
            }
        }
        sort(fucking_graph.begin(),fucking_graph.end());
        UnionFind uf(size);
        int count = 0;
        int result = 0;
        for(int i = 0; i < fucking_graph.size() and count < size ;i++){
            int node1 = fucking_graph[i].second.first;
            int node2 = fucking_graph[i].second.second;
            int weight = fucking_graph[i].first;
            if(uf.join(node1,node2)){
                result+=weight;
                count++;
            }
        }
        return result;
    }
};
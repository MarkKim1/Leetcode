class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minheap;
        set<int> visited;
        minheap.push({0,0});
        int n = points.size();
        int edgesUsed = 0;
        int result = 0;
        
        while(edgesUsed < n){
            auto top = minheap.top();
            minheap.pop();
            int distance = top.first;
            int node = top.second;
            
            if(visited.count(node)){
                continue;
            }
            visited.insert(node);
            edgesUsed++;
            result+=distance;
            
            for(int i = 0; i < n; i++){
                if(not visited.count(i)){
                    int manhattanDistance = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    minheap.push({abs(manhattanDistance),i});
                }
            }
        }
        return result;
        
    }
};
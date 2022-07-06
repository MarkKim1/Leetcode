class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        heap.push({0,0});
        vector<bool> visited(n);
        int mstCost = 0;
        int edgesUsed = 0;
        while(edgesUsed < n){
            pair<int,int> topElement = heap.top();
            heap.pop();
            int weight = topElement.first;
            int currNode = topElement.second;
            
            if(visited[currNode]){
                continue;
            }
            visited[currNode] = true;
            edgesUsed++;
            mstCost+=weight;
            for(int nextNode = 0; nextNode < n; nextNode++){
                if(!visited[nextNode]){
                    int nextweight = abs(points[currNode][0] - points[nextNode][0]) + abs(points[currNode][1] - points[nextNode][1]);
                    heap.push({nextweight,nextNode});
                }
               
            }
        }
        return mstCost;
    }
};
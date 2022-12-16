class Solution {
public:
    int ans = INT_MAX;
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        vector<bool>visited(bikes.size(),false);
        backtrack(workers,0,bikes,0,0,visited);
        return ans;
    }
    void backtrack(vector<vector<int>>& workers, int workerIndex,
                   vector<vector<int>>& bikes, int bikeIndex,
                   int curr, vector<bool>& visited){
        if(workerIndex >= workers.size()){
            ans = min(ans,curr);
            return;
        }
        for(int i = bikeIndex; i < bikes.size(); i++){
            if(visited[i] == false){
                int distance = manhattan(bikes[i],workers[workerIndex]);
                visited[i] = true;
                curr += distance;
                backtrack(workers, workerIndex + 1, bikes, bikeIndex, curr, visited);
                curr-= distance;
                visited[i] = false;
            }
        }
    }
    int manhattan(vector<int>& bike, vector<int>& worker){
        return abs(bike[0] - worker[0]) + abs(bike[1] - worker[1]);
    }
};
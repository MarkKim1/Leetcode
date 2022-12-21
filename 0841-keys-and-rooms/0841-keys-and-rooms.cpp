class Solution {
public:
    unordered_map<int,unordered_set<int>> graph;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                graph[i].insert(rooms[i][j]);
            }
        }
        make_graph(0,visited);
        for(int i = 1; i < visited.size(); i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
    void make_graph(int curr, vector<bool>& visited){
        unordered_set<int> set = graph[curr];
        for(auto each : set){
            if(visited[each] == true){
                continue;
            }
            visited[each] = true;
            make_graph(each,visited);
        }
    }
};
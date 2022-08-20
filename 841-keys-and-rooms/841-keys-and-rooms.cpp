class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> result(rooms.size(),false);
        dfs(result,rooms,0);
        for(int i = 0; i < result.size(); i++){
            if(result[i] == false){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<bool>& result, vector<vector<int>>& rooms, int curr){
        if(result[curr] == true) return;
        result[curr] = true;
        for(int i = 0; i < rooms[curr].size(); i++){
            dfs(result,rooms, rooms[curr][i]);
        }
    }
};
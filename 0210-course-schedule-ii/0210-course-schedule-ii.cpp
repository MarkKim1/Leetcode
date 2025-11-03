class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<int> degree(numCourses);
        unordered_map<int,vector<int>> map;
        for(auto& each : prerequisites){
            map[each[1]].push_back(each[0]);
            degree[each[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == 0){
                q.push(i);
                degree[i]--;
                result.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            numCourses--;
            for(int i = 0; i < map[curr].size(); i++){
                int next = map[curr][i];
                degree[next]--;
                if(degree[next] == 0){
                    q.push(next);
                    result.push_back(next);
                }
            }
        }
        return numCourses == 0 ? result : vector<int>();
    }
};
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> map;
        for(int i = 0 ; i < routes.size(); i++){
            for(int each : routes[i]){
                map[each].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        set<int> seen;
        q.push({source,0});
        seen.insert(source);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [stop,bus] = q.front();
                if(stop == target){
                    return bus;
                }
                q.pop();
                //for each index of routes[index]
                for(auto each : map[stop]){
                    //for each routes[each][a]
                    for(auto a : routes[each]){
                        if(seen.find(a) == seen.end()){
                            seen.insert(a);
                            q.push({a,bus+1});
                        }
                    }
                    routes[each].clear();
                }
            }
        }
        return -1;
    }
};
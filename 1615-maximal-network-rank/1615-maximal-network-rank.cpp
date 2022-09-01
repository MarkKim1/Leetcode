class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> map;
        for(int i = 0; i < roads.size(); i++){
            map[roads[i][0]].push_back(roads[i][1]);
            map[roads[i][1]].push_back(roads[i][0]);
        }
        int ans = INT_MIN;
        for(int i = 0; i <n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int a = map[i].size();
                int b = map[j].size();
                if(find(map[i].begin(),map[i].end(),j) == map[i].end()){
                    ans = max(ans,a+b);
                }else{
                    ans = max(ans,a+b-1);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        int ans = 0;
        for(int i = 0 ; i < edges.size(); i++){
            map[edges[i][0]]++;
            map[edges[i][1]]++;
            if(map[edges[i][0]] > map[edges[i][1]]){
                ans = edges[i][0];
            }else{
                ans = edges[i][1];
            }
        }
        return ans;
    }
};
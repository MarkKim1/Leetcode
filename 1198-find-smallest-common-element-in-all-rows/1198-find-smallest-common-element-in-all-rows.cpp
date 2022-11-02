class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int> map;
        int ans = INT_MAX;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                map[mat[i][j]]++;
                if(map[mat[i][j]] == mat.size()){
                    ans = min(ans,mat[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
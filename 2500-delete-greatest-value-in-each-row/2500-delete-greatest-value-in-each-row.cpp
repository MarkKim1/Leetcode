class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            sort(grid[i].begin(), grid[i].end(),greater<int>());
        }
        int result = 0;
        for(int i = 0; i < grid[0].size(); i++){
            int intmax = INT_MIN;
            for(int j = 0; j < grid.size(); j++){
                intmax = max(intmax, grid[j][i]);
            }
            result += intmax;
        }
        return result;
    }
};
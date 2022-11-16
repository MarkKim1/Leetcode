class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int newrow = grid.size()-3;
        int newcol = grid[0].size()-3;
        int ans = 0;
        for(int i = 0; i <= newrow; i++){
            for(int j = 0; j <= newcol; j++){
                int count = 0;
                for(int a = 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        if(a == 1 and (b == 0 || b == 2)){
                            continue;
                        }
                        count += grid[a+i][b+j];
                    }
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
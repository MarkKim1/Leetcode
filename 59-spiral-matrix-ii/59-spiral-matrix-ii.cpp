class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> visited(n,vector<int>(n,-1));
        int up = 0;
        int left = 0;
        int down = n-1;
        int right = n-1;
        vector<vector<int>> result(n,vector<int>(n));
        int count = n*n;
        int number = 0;
        while(number < count){
            //traverse left to right
            for(int col = up; col <= right; col++){
                if(visited[up][col] == -1)
                    result[up][col] = ++number;
                visited[up][col] = 1;
            }
            //traverse downwards
            for(int row = up+1; row <= down; row++){
                if(visited[row][right] == -1)
                    result[row][right] = ++number;
                visited[row][right] = 1;
            }
            //traverse left to right
            for(int col = right-1; col >= left; col--){
                if(visited[down][col] == -1)
                    result[down][col] = ++number;
                visited[down][col] = 1;
            }
            //traverse upwards
            for(int row = down-1; row >= up; row--){
                if(visited[row][left] == -1)
                    result[row][left] = ++number;
                visited[row][left] = 1;
            }
            up++;
            left++;
            down--;
            right--;
        }
        return result;
    }
};
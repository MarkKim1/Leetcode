class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
    void dfs(vector<vector<int>>& image, int ROW,int COL,int color,int source_color){
        if(ROW < 0 || COL < 0 || ROW >= image.size() || COL >= image[0].size() || image[ROW][COL] != source_color || image[ROW][COL] == color){
            return;
        }
        image[ROW][COL] = color;
        dfs(image,ROW+1,COL,color,source_color);
        dfs(image,ROW,COL+1,color,source_color);
        dfs(image,ROW-1,COL,color,source_color);
        dfs(image,ROW,COL-1,color,source_color);
    }
};
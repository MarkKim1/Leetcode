class Solution {
public:
    bool DFS(vector<vector<int>>& image,int x, int y, int sr, int sc, int newColor,int start){
        int visited = 0;
        if(sr <= -1 || sr >= x || sc <= -1 || sc >= y ){
            return false;    
        }
        
        else if(image[sr][sc] == start){
            image[sr][sc] = newColor;
            DFS(image,x,y,sr-1,sc,newColor,start);
            DFS(image,x,y,sr,sc-1,newColor,start);
            DFS(image,x,y,sr+1,sc,newColor,start);
            DFS(image,x,y,sr,sc+1,newColor,start);
            return true;
        }
        return false;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor){
            return image;
        }
        int x = image.size();
        int y = image[0].size();
        int start = image[sr][sc];
        if(DFS(image,x,y,sr,sc,newColor,start)){
            return image;
        }
        return image;
    }
};
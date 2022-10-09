class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        int result = 0;
         for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j]== 'B'){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j]== 'B'){
                    if(row[i] == 1 and col[j] == 1){
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
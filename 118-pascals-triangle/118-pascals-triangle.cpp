class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return{{1}};
        vector<vector<int>> result;
        vector<int> current;
        result.push_back({1});
        result.push_back({1,1});
        for(int i = 2; i <numRows; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0){
                    current.push_back(1);
                    continue;
                }
                if(j == i){
                    current.push_back(1);
                    continue;
                }
                current.push_back(result[i-1][j] + result[i-1][j-1]);
            }
            result.push_back(current);
            current.clear();
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> sub_result;
        result.push_back({1});
        for(int rowNum = 1; rowNum < numRows; rowNum++){
            vector<int> prev_row = result[rowNum-1];
            sub_result.push_back(1);
            for(int col = 1; col < prev_row.size(); col++){
                sub_result.push_back(prev_row[col-1] + prev_row[col]);
            }
            sub_result.push_back(1);
            result.push_back(sub_result);
            sub_result.clear();
        }
        return result;
    }
};
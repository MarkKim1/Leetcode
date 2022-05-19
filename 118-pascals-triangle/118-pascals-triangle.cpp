class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for(int rowNum = 1; rowNum < numRows; rowNum++){
            vector<int> currRow;
            vector<int> prevRow = triangle[rowNum-1];
            currRow.push_back(1);
            for(int col = 1; col < prevRow.size(); col++){
                currRow.push_back(prevRow[col-1] + prevRow[col]);
            }
            currRow.push_back(1);
            triangle.push_back(currRow);
        }
        return triangle;
    }
};
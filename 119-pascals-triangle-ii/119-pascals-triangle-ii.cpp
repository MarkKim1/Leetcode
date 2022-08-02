class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return{1};
        if(rowIndex == 1) return {1,1};
        vector<int> result = {1,1};
        for(int i = 2; i <= rowIndex; i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j = 1; j < i; j++){
                temp.push_back(result[j] + result[j-1]);
            }
            temp.push_back(1);
            result = temp;
        }
        return result;
    }
};
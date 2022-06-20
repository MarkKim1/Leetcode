class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        int temp = heights[heights.size()-1];
        for(int i = heights.size()-2; i >= 0; i--){    
            if(heights[i] > temp){
                result.push_back(i);
                temp = heights[i];
            }
        }
        reverse(result.begin(),result.end());
        result.push_back(heights.size()-1);
        return result;
    }
};
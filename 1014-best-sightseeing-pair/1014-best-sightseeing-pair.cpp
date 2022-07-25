class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = INT_MIN;
        int maxSoFar = values[0] + 0;
        for(int i = 1; i < values.size(); i++){
            maxSoFar = max(maxSoFar,values[i-1]+i-1);
            result = max(result,values[i]-i + maxSoFar);
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }
        
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > newInterval[1]){
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
            else if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            }
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        vector<int> sub = intervals[0];
        int first = 0;
        int second = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(sub[1] >= intervals[i][0]){
                first = min(sub[0],intervals[i][0]);
                second = max(sub[1],intervals[i][1]);
                sub = {first,second};
            }else{
                result.push_back(sub);
                //result.push_back(intervals[i]);
                sub = intervals[i];
            }
        }
        result.push_back(sub);
        return result;
    }
};
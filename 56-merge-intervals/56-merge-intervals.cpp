class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merge;
        sort(intervals.begin(),intervals.end());
        merge.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(merge.back()[1] >= intervals[i][0]){
                merge.back()[1] = max(merge.back()[1],intervals[i][1]);
            }else{
                merge.push_back(intervals[i]);
            }
        }
        return merge;
    }
};
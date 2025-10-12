class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> ans;
        vector<pair<int,int>> pairs;
        for(int i = 0; i < interval.size(); i++){
            pairs.push_back({interval[i][0], interval[i][1]});
        }
        sort(pairs.begin(), pairs.end());
        for(int i = 0; i < pairs.size(); i++){
            int start = pairs[i].first;
            int end = pairs[i].second;
            while(!ans.empty() and ans.back()[1] >= start){
                start = min(start,ans.back()[0]);
                end = max(end,ans.back()[1]);
                ans.pop_back();
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
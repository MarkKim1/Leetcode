class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,int> popular,sum_views;
        vector<vector<string>> ans;
        int max_views = INT_MIN;
        for(int i = 0; i < ids.size(); i++){
            max_views = max(max_views,sum_views[creators[i]] += views[i]);
            auto it = popular.find(creators[i]);
            if(it == end(popular)){
                popular[creators[i]] = i;
            }else if(views[i] >= views[it->second]){
                if(views[i] == views[it->second]){
                    it->second = ids[i] < ids[it->second] ? i : it->second;
                }else{
                    it->second = i;
                }
            }
        }
        for(auto [creator,views] : sum_views){
            if(views == max_views){
                ans.push_back({creator,ids[popular[creator]]});
            }
        }
        return ans;
    }
};
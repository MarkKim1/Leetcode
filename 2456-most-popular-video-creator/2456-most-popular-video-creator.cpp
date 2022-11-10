class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        // add total views
        unordered_map<string,int> popularity;
        unordered_map<string,map<string,int>> fuck;
        int currmax = INT_MIN;
        vector<string> consider;
        for(int i = 0; i < creators.size(); i++){
            popularity[creators[i]] += views[i];
            currmax = max(popularity[creators[i]],currmax);
        }
        for(int i = 0; i < creators.size(); i++){
            fuck[creators[i]][ids[i]] = views[i];
        }
        for(auto cr : popularity){
            if(cr.second == currmax){
                consider.push_back(cr.first);
            }
        }
        for(auto creator : consider){
            int maxview = INT_MIN;
            string minID = "zzzzzzzzzzz";
            for(auto each : fuck[creator]){
                maxview = max(maxview,each.second);
            }
            for(auto each : fuck[creator]){
                if(each.second == maxview){
                    minID = min(each.first,minID);
                }
            }
            ans.push_back({creator,minID});
        }
        return ans;
    }
};
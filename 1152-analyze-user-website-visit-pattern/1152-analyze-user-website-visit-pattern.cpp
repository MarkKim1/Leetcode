class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
      unordered_map<string,map<int,string>> map;
      unordered_map<string,int> count;
      string result = "";
      int max_count = 0;
      for(int i = 0; i < username.size(); i++){
        map[username[i]][timestamp[i]] = website[i];
      }
      for(auto a : map){
        unordered_set<string> set;
        for(auto it1 = begin(a.second); it1 != end(a.second); it1++){
          for(auto it2 = next(it1); it2 != end(a.second); it2++){
            for(auto it3 = next(it2); it3 != end(a.second); it3++){
              set.insert(it1->second + "$" + it2->second + "$" + it3->second);
            }
          }
        }
        for(auto str : set){
          count[str]++;
        }
      }
      for(auto c : count){
        if(c.second >= max_count){
          result = result == "" || c.second > max_count ? c.first : min(result,c.first);
          max_count = c.second;
        }
      }
      string temp = "";
      vector<string> ans;
      for(int i = 0; i < result.size(); i++){
        if(!isalpha(result[i])){
          ans.push_back(temp);
          temp.erase();
          continue;
        }
        temp+=result[i];
      }
      ans.push_back(temp);
      return ans;
    }
};
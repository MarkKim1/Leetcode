class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& user, vector<int>& time, vector<string>& site) {
      unordered_map<string,map<int,string>> map;
      unordered_map<string,int> count;
      int max_count = 0;
      string result = "";
      for(int i = 0; i < user.size(); i++){
        map[user[i]][time[i]] = site[i];
      }
      for(auto each : map){
        unordered_set<string> set;
        for(auto it1 = begin(each.second); it1 != end(each.second); it1++){
          for(auto it2 = next(it1); it2 != end(each.second); it2++){
            for(auto it3 = next(it2); it3 != end(each.second); it3++){
              set.insert(it1->second + "@" + it2->second + "@" + it3->second);
            }
          }
        }
        for(auto set_each : set){
          count[set_each]++;
        }
      }
      for(auto count_each : count){
        if(count_each.second >= max_count){
          result = result == "" || count_each.second > max_count ? count_each.first : min(result,count_each.first);
          max_count = count_each.second;
        }
      }
      vector<string> ans;
      string temp = "";
      for(int i = 0; i < result.size(); i++){
        if(!isalpha(result[i])){
          ans.push_back(temp);
          temp.erase();
          continue;
        }
        temp.push_back(result[i]);
      }
      ans.push_back(temp);
      return ans;
    }
};
// ["joe","home",1],["joe","about",2],["joe","career",3],
//["james","home",4], ["james","cart",5],["james","maps",6],["james","home",7],
//["mary","home",8], ["mary","about",9], and ["mary","career",6].
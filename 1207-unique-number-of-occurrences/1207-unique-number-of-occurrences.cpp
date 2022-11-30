class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> set;
        for(int i = 0 ; i < arr.size(); i++){
            map[arr[i]]++;
        }
        for(auto each : map){
            if(set.count(each.second)){
                return false;
            }
            set.insert(each.second);
        }
        return true;
    }
};
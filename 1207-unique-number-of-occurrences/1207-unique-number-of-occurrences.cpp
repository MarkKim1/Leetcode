class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> set;
        for(int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }
        for(auto a:map){
            set.insert(a.second);
        }
        if(map.size() == set.size()){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        int maxDistance = INT_MAX;
        vector<string> str;
        for(int i = 0; i < list1.size(); i++){
            hashmap[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); i++){
            if(hashmap.find(list2[i]) != hashmap.end()){
                if(hashmap[list2[i]] + i < maxDistance){
                    maxDistance = hashmap[list2[i]] + i;
                    str.clear();
                    str.push_back(list2[i]);
                }
                else if(hashmap[list2[i]] + i == maxDistance){
                    str.push_back(list2[i]);
                }
            }
        }
        
        return str;
    }
};
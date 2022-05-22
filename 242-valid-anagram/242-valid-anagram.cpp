class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            auto it = map.find(t[i]);
            if(it != map.end()){
                if(it->second == 0){
                    return false;
                }
                it->second--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};
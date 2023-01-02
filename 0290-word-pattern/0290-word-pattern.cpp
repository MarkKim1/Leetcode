class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        set<string> set;
        string temp = "";
        stringstream ss;
        ss << s;
        vector<string> str_vec;
        while(getline(ss,temp,' ')){
            str_vec.push_back(temp);
        }
        if(pattern.size() != str_vec.size()) return false;
        for(int i = 0; i < pattern.size(); i++){
            if(map.find(pattern[i]) != map.end()){
                if(map[pattern[i]] != str_vec[i]){
                    return false;
                }
            }else{
                if(set.count(str_vec[i])){
                    return false;
                }
            }
            map[pattern[i]] = str_vec[i];
            set.insert(str_vec[i]);
        }
        return true;
    }
};
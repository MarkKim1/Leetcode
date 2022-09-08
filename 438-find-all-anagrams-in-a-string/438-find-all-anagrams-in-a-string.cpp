class Solution {
public:
    int count = 0;
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char,int> p_map;
        unordered_map<char,int> s_map;
        if(s.size() < p.size()) return result;
        for(int i = 0; i < p.size(); i++){
            p_map[p[i]]++;
        }
        for(int i = 0; i < s.size(); i++){
            s_map[s[i]]++;
            if(i >= p.size()-1){
                if(s_map == p_map){
                    result.push_back(i-(p.size()-1));
                }
                s_map[s[i-(p.size()-1)]] > 1 ? s_map[s[i-(p.size()-1)]]-- : s_map.erase(s[i-(p.size()-1)]);
            }
        }
        return result;
    }
};
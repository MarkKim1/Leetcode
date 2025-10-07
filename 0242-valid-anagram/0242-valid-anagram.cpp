class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> check(256, 0);
        for(int i = 0; i < s.size(); i++){
            check[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            check[t[i]]--;
            if(check[t[i]] < 0){
                return false;
            }
        }
        return true;
    }
};
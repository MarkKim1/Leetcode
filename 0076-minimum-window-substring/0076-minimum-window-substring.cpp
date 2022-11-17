class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        int left = 0;
        int right = 0;
        int maxStart = 0;
        int minEnd = INT_MAX;
        int count = t.size();
        for(int i = 0; i < t.size(); i++){
            map[t[i]]++;
        }
        while(right < s.size()){
            if(map[s[right]] > 0){
                count--;
            }
            map[s[right]]--;
            right++;
            while(count == 0){
                if(right-left < minEnd){
                    maxStart = left;
                    minEnd = right-left;
                }
                map[s[left]]++;
                if(map[s[left]] > 0){
                    count = 1;
                }
                left++;
            }
        }
        if(minEnd != INT_MAX){
            return s.substr(maxStart,minEnd);
        }
        return "";
    }
};
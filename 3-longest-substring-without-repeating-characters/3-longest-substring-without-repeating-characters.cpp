class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int max_length = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            if(map.find(s[i]) != map.end()){
                left = max(left,map[s[i]]+1);
            }
            map[s[i]] = i;
            max_length = max(max_length,i-left+1);
        }
        return max_length;
    }
};
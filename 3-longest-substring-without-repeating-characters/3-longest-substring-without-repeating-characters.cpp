class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128,-1);
        int left = 0;
        int right = 0;
        int res = 0;
        
        while(right < s.size()){
            char r = s[right]; // r = a;
            int index = chars[r]; //int index = chars[65] => int index = 0;
            if(index != -1 && index >= left && index < right){
                left = index +1;
            }
            res = max(res, right - left + 1);
            
            chars[r] = right;
            right++;
        }
        return res;
    }
};
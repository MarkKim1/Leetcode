class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map;
        int max_length = 0;
        int left = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            max_length = max(max_length,++map[s[i]]);
            if((i -left + 1) - max_length <= k){
                result = max(result,i-left + 1);
            }else{
                map[s[left]]--;
                left++;
            }
        }
        return result;
    }
};
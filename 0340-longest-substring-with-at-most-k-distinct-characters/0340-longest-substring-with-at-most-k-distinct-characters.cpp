class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        unordered_map<char,int> map;
        int ans = INT_MIN;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
            while(map.size() > k){
                map[s[left]]--;
                if(map[s[left]] == 0){
                    map.erase(s[left]);
                }
                left++;
            }
            if(map.size() <= k){
                ans = max(ans,i-left+1);
            }
        }
        return ans;
    }
};
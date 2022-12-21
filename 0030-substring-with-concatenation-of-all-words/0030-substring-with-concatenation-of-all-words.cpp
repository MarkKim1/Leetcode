class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> words_map;
        int maxLen = 0;
        int eachLen = 0;
        for(int i = 0; i < words.size(); i++){
            words_map[words[i]]++;
            maxLen+=words[i].size();
            eachLen = words[i].size();
        }
        int i = 0;
        vector<int> ans;
        while(i + maxLen <= s.size()){
            string sub = s.substr(i,maxLen);
            if(isSubstring(words_map,sub,eachLen)){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
    bool isSubstring(map<string,int> words_map, string s, int eachLen){
        map<string,int> seen;
        for(int i = 0; i < s.size(); i+=eachLen){
            string curr = s.substr(i,eachLen);
            seen[curr]++;
            if(seen[curr] > words_map[curr]){
                return false;
            }
        }
        return seen == words_map;
    }
};
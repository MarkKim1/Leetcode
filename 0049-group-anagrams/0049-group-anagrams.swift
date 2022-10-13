class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            map[strSort(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto a : map){
            ans.push_back(a.second);
        }
        return ans;
    }
    string strSort(string str) {
        int arr[26] = {0};
        for(int i = 0; i < str.size(); i++){
            arr[str[i]-'a']++;
        }
        string result = "";
        for(int i = 0; i < 26; i++){
            result+=string(arr[i],i + 'a');
        }
        return result;
    }
};
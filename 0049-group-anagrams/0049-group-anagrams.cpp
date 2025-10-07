class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            map[curr].push_back(strs[i]);

        }
        for(auto& [first, second] : map){
            ans.push_back(second);
        }
        return ans;
    }
};